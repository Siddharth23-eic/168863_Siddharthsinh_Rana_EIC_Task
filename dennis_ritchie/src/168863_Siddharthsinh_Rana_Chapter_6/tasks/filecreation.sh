#!/bin/bash

# Prompt for input
chapter=6
read -p "Enter Excercise number: " exercise
# Get current date
current_date=$(date +"%d/%m/%Y")

filename=$(printf "168863_Siddharthsinh_Rana_DR_Ch%d_E%d.c" "$chapter" "$exercise")
exercise_label=$(printf "%d.%d" "$chapter" "$exercise")

# Check if file already exists
if [ -f "$filename" ]; then
    echo "File '$filename' already exists. Skipping creation."
    exit 1
fi
    cat << EOF > "$filename"
/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: $current_date
 * Chapter: $chapter
 * Exercise: $exercise_label
 * Description:
 */

#include <stdio.h>
#include <stdint.h>

int32_t exercise${chapter}_${exercise}(void) {
    // Your code goes here

    return 0;
}

EOF

    echo "Created: $filename with Exercise: $exercise_label"

