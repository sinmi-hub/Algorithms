#!/usr/bin/env bash

re_cap_letter='^[A-Z ]+$'
re_key='[0-9]+'

prompt() {
    echo $1
    echo -n ">"
}


validate_msg(){
    [[ $1 =~ $re_cap_letter ]] && return 0 || return 1
}


validate_key(){
    [[ (($1 =~ $re_key)) && (($1 -gt 0)) && (($1 -lt 25)) ]] && return 0 || return 1
}


caesar_cipher(){
    local op=$1
    
    prompt "Enter a message:"
    read -r message
    prompt "Enter a key:"
    read -r key
    
    if validate_msg "$message" && validate_key "$key"; then
        if [[ $op == "e" ]]; then
            echo "Encrypted message:" && process "$op" "$message" "$key"
            
        else
            echo "Decrypted message:" && process "$op" "$message" "$key"
        fi
    
    else
            echo "Invalid message or invalid key detected!"
        fi
}


process(){
    local msg=$2
    local key=$3
    
    for (( i=0; i<${#msg}; i++ )); do
    
       if [[ "${msg:$i:1}" == ' ' ]]; then
            echo -n " "
        else
            letter_ascii=$(printf "%d" "'${msg:$i:1}")
            base_A=$(printf "%d" "'A")
            
            # -- DIFFERENCE BTWN ENCRYPTION AND DECRYPTION--------
            if [[ $op == "e" ]]; then
                temp=$(( (letter_ascii - base_A + $key) % 26 + base_A ))
            else
                temp=$(( ((letter_ascii - base_A - $key + 26) % 26) + base_A))
            fi
            #---------------------------------------------------------
            
            char=$(printf \\$(printf '%03o' $temp))
            echo -n "$char"
        fi
    done
}

#------------ USER INTERACTION ------------------
echo "Type 'e' to encrypt, 'd' to decrypt a message:"
prompt "Enter a command:"
read -r state

case $state in
    "e")
        caesar_cipher "e"
        ;;
        
    "d")
        caesar_cipher "d"
        ;;
        
    *)
        echo "Invalid command!"
        ;;
esac

