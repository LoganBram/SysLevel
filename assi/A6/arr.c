#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arr.h"

/*
 * Reads count int values from f storing the values in 
 * the specified array.
 *
 * Does not close the file f.
 */
void arr_readn(FILE *f, size_t count, int *arr) {
    int value;
    for(size_t i = 0; i < count; i++){
        fscanf(f, " %d,", &value);
        //store in array
        arr[i] = value;
    }
    
}


/*
 * Reads characters from f storing the characters in the array 
 * pointed at by s. Stops reading when a newline character '\n' 
 * is reached, or when max_length characters are read. A newline
 * character is never stored in the array pointed at by s.
 * A null terminator is always stored to indicate the end of the
 * string.
 *
 * Returns true if a newline character is reached (indicating
 * that an entire line of the file was read). Returns false
 * if the last character read was not the newline character,
 * or if reading from the file failed for some reason.
 *
 * Does not close the file f.
 */
bool arr_readline(FILE *f, size_t max_length, char *s) {
    if (!f || max_length == 0) {
        return false;
    }

    int c;
    size_t i = 0;

    while (i < max_length - 1) {
        c = fgetc(f);

       
        if (c == EOF) {
            if (feof(f)) {  
                s[i] = '\0';
                return false;  
            }
            if (ferror(f)) { 
                s[i] = '\0';
                return false;
            }
        }

        // checkfor newline character
        if (c == '\n') {
            //end string
            s[i] = '\0';
            return true;  
        }

        s[i] = (char)c;
        i++;
    }

    s[i] = '\0'; // terminate the string reagrdles
    return false; //false if length reached wiithout \n
}


/*
 * Extracts integer values from a string where the integer values
 * are separated from one another by a single comma (no spaces).
 * The integer values are returned in a newly allocated array
 * having capacity exactly equal to the number of integers extracted.
 * The number of extracted integers is written into the object
 * pointed at by n.
 */


int* arr_fromstr(const char *s, size_t *n) {
    int count = 0;
    char *str = strdup(s); // Copy the string to a modifiable array

    // Count commas
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',') {
            count++;
        }
    }

    int *arr = malloc((count + 1) * sizeof(int)); // Dynamically allocate array
    if (arr == NULL) {
        free(str);
        return NULL; // Allocation failed
    }

    *n = count + 1;
    char *token = strtok(str, ",");
    int idx = 0;

    while (token != NULL) {
        arr[idx++] = atoi(token);
        token = strtok(NULL, ",");
    }

    *n = count+1;

    free(str); // Free the copied string
    return arr;
}






/*
 * Uncompresses the n element compressed array enc returning
 * a pointer to the first element of a new array
 * containing the uncompressed array. Writes the length of the
 * uncompressed array into the object pointed at by dec_len.
 *
 * The returned array has no excess capacity (i.e.,
 * all values in the returned array are meaningful).
 */
int *arr_decode(size_t n, const int *enc, size_t *dec_len) {
    int *repeatcount = malloc((n / 2) * sizeof(int));
    int *values = malloc((n / 2) * sizeof(int));
    if (!repeatcount || !values) {
        free(repeatcount);  // Free in case one of them was successfully allocated
        free(values);
        return NULL;
    }

    //getting da values for both arrays
    for (size_t i = 0; i < n; i += 2) {
        repeatcount[i / 2] = enc[i];
        values[i / 2] = enc[i + 1];
    }

    //get size for the array
    int decomp_array_size = 0;
    for (size_t i = 0; i < n / 2; i++) {
        decomp_array_size += repeatcount[i];
    }

    //make decomp array basedo n size
    int *decomp_arr = malloc(decomp_array_size * sizeof(int));
    if (decomp_arr == NULL) {
        free(repeatcount);
        free(values);
        return NULL;
    }

    int pos = 0;
    for (size_t i = 0; i < n / 2; i++) {
        for (int j = 0; j < repeatcount[i]; j++) {
            decomp_arr[pos++] = values[i];
        }
    }

    *dec_len = decomp_array_size;
    //free the temp arrays
    free(repeatcount); 
    free(values);

    return decomp_arr;
}


