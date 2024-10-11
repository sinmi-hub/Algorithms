#!/usr/bin/env bash

re_cap_letter='^[A-Z]$'
re_key='^[0-9]$'

prompt() {
    echo $1
}

validate_letter(){
    [[ $1 =~ $re_cap_letter ]]
}

validate_key(){
    [[ $1 =~ $re_key ]]
}

encrypt(){
    letter_ascii=$(printf "%d" "'$1") # convert letter to ascii
    base_A=$(printf "%d" "'A")
    temp=$(( (letter_ascii - base_A + $2) % 26 + base_A )) # shift letter by key
    char=$(printf \\$(printf '%03o' $temp)) # convert ascii to letter
    echo "Encrypted letter: ${char}"
}

# get letter to convert, and key to shift by
prompt "Enter an uppercase letter: "
read -r letter
prompt "Enter a key: "
read -r key


if validate_letter "$letter" && validate_key "$key"; then
    encrypt $letter $key
else
    echo -e "Invalid key or letter!"
fi
