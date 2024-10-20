#!/usr/bin/env bash
re_msg='^[A-Z ]+$'
re_filenme='^[a-zA-Z]+\.[a-zA-Z]+'

prompt() {
    echo $1
    # echo -n ">"
}

menu(){
    echo -e "0. Exit\n1. Create a file\n2. Read a file\n3. Encrypt a file\n4. Decrypt a file"
}

validate_msg(){
    [[ $1 =~ $re_msg ]] && return 0 || return 1
}

validate_fnme(){
     [[ $1 =~ $re_filenme ]] && return 0 || return 1
}

request_filename(){
    prompt "Enter the filename:"
    read -r filename
}


#------------ USER INTERACTION ------------------
echo -e "Welcome to the Enigma!\n"

while true; do
    menu
    prompt "Enter an option:"
    read -r option

    case $option in
        0)
            echo "See you later!"
            exit 0
        ;;

        1)
            request_filename

            if validate_fnme "$filename"; then
                prompt "Enter a message:"
                read -r msg
                if validate_msg "$msg"; then
                    echo "$msg" >> "$filename"
                    echo "The file was created successfully!"
                else
                    echo "This is not a valid message!"
                fi
            else
                echo "File name can contain letters and dots only!"
            fi
        ;;

        2)
            request_filename

            if validate_fnme "$filename" && [[ -e $filename ]]; then
                echo "File content:"
                cat $filename
            else
                echo "File not found!"
            fi      
        ;;

        3)
           request_filename

            if  [[ -e $filename ]]; then
                prompt "Enter password:"
                read -r password
                openssl enc -aes-256-cbc -e -pbkdf2 -salt -in "$filename" -out "${filename}.enc" -pass pass:"$password" &>/dev/null
                exit_code=$?
                if [[ $exit_code -eq 0 ]]; then
                    rm "$filename"
                    echo "Success"
                else
                    echo "Fail"
                fi
            else
                echo "File not found!"
            fi   
        ;;

        4)
            request_filename

            if [[ -e $filename ]]; then
                prompt "Enter password:"
                read -r password
                openssl enc -aes-256-cbc -d -pbkdf2 -salt -in "$filename" -out "${filename%.enc}" -pass pass:"$password" &>/dev/null
                exit_code=$?
                if [[ $exit_code -eq 0 ]]; then
                    rm "$filename"
                    echo "Success"
                else
                    echo "Fail"
                fi
            else
                echo "File not found!"
            fi
        ;;

        *)
            echo "Invalid option!"
        ;;
    esac
done


