#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include <ctype.h>

void print_hash(gpointer key, gpointer value, gpointer user_data) {
    char* better_key = key;
    printf("%s: %i\n", better_key, GPOINTER_TO_INT(value));
}

int main(int argc, char** argv) {

    GHashTable *hash = g_hash_table_new(g_str_hash, g_int_equal);

    FILE *ptr_file;
    char line_buf[1000];
    char word_buf[50];

    ptr_file =fopen("jane_eyre.txt","r");
    if (!ptr_file) {
        return 1;
    }

    int l_index = 0;
    int w_index = 0;
    while(fgets(line_buf,1000, ptr_file)!=NULL) {
        while(line_buf[l_index]!='\n') {
          if(isalpha(line_buf[l_index])==0) {
            word_buf[w_index+1] = '\0';
            int val = g_hash_table_lookup(hash, word_buf);

            if(val==NULL) {
              g_hash_table_insert(hash, g_strdup(word_buf), GINT_TO_POINTER(1));
            }
            else {
              g_hash_table_insert(hash, g_strdup(word_buf), GINT_TO_POINTER(val+1));
            }

            memset(word_buf, 0, sizeof word_buf);
            w_index = 0;
            l_index++;
          }
          else {
            word_buf[w_index] = line_buf[l_index];
            w_index++;
            l_index++;
          }
        }
        w_index = 0;
        l_index = 0;
        memset(word_buf, 0, sizeof word_buf);
    }

		fclose(ptr_file);
    g_hash_table_foreach(hash, print_hash, NULL);

    return 0;
}
