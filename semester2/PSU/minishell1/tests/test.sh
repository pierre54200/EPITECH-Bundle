#!/bin/bash

function test () {

    i=0
    t=1
    valgrind=0
    valgrindt=0
    base=0
    baset=0
    path=0
    patht=0
    env=0
    envt=0
    unsetenv=0
    unsetenvt=0
    cd=0
    cdt=0
    spaces=0
    spacest=0
    error=0
    errort=0

    echo -e "\n\e[1;36m------------------------[BUILD CHECKING]------------------------\n\e[0m";

        echo -e "\e[1;37mBuild :" ;
        make re > /dev/null 2> /dev/null
        if [ $? -eq 0 ]; then
            echo -e "\e[1;32mSUCESS\n\e[0m"
        else
            echo -e "\e[1;31mFAILURE\n\e[0m"
            exit 0
        fi


    echo -e "\n\n\e[1;36m------------------------[VALGRIND CHECKING]------------------------\n\e[0m";

    commands=("" "randomcmd" "ls" "pwd" "cd" "env" "setenv test" "unsetenv PATH")
    output_files=("nothing" "randomcmd" "ls" "pwd" "cd" "env" "setenv" "unsetenv")

        for ((index=0; index<${#commands[@]}; index++)); do
            echo -e "\e[1;37mTest n°$t (${commands[index]}) :";
            echo -e "${commands[index]}" | valgrind --leak-check=full --show-leak-kinds=all ./mysh > "bashtest/valgrind_output/${output_files[index]}.txt" 2>&1
            if grep -q "ERROR SUMMARY: 0 errors" "bashtest/valgrind_output/${output_files[index]}.txt"; then
                echo -e "\e[1;32mSUCESS\n\e[0m"
                ((i++))
                ((valgrind++))
            else
                echo -e "\e[1;31mFAILURE (Check output in valgrind_output)\n\e[0m"
            fi
        ((t++))
        ((valgrindt++))
        done

        echo -e "\e[1;37mTest n°$t (setenv & unsetenv & env each) :";
        (echo -e "env" && echo -e "setenv test bonjourjesuisuntest" && echo -e "env" && echo -e "unsetenv test" && echo -e "env") | valgrind --leak-check=full --show-leak-kinds=all ./mysh > bashtest/valgrind_output/setenvandunsetenv.txt 2>&1
        if grep -q "ERROR SUMMARY: 0 errors" bashtest/valgrind_output/setenvandunsetenv.txt; then
            echo -e "\e[1;32mSUCESS\n\e[0m"
            ((i++))
            ((valgrind++))
        else
            echo -e "\e[1;31mFAILURE (Check output in valgrind_output)\n\e[0m"
        fi
        ((t++))
        ((valgrindt++))

    echo -e "\n\n\e[1;36m-------------------------[BASE TEST]-------------------------\n\e[0m";

    commands2=("" "ls" "./bashtest/executable" "azertyuioptestabc")
    descriptions=("empty" "simple exec" "run simple command" "wrong simple command")

        for ((index=0; index<${#commands2[@]}; index++)); do
            echo -e "\e[1;37mTest n°$t (${descriptions[index]}) :";
            echo -e "${commands2[index]}" | ./mysh > bashtest/mysh.txt 2>&1
            echo -e "${commands2[index]}" | tcsh > bashtest/tcsh.txt 2>&1
            sdiff -s bashtest/mysh.txt bashtest/tcsh.txt
            if [ $? -eq 0 ]; then
                echo -e "\e[1;32mSUCESS\n\e[0m"
                ((i++))
                ((base++))
            else
                echo -e "\e[1;31mFAILURE\n\e[0m"
            fi
            rm bashtest/tcsh.txt
            rm bashtest/mysh.txt
            ((t++))
            ((baset++))
        done

    echo -e "\n\n\e[1;36m-------------------------[PATH HANDLING]-------------------------\n\e[0m";

            echo -e "\e[1;37mTest n°$t (unsetenv PATH handling) :";
            echo -e 'unsetenv PATH\nls\npwd' | ./mysh > bashtest/mysh.txt 2>&1
            sdiff -s bashtest/mysh.txt bashtest/cmdnotfound.txt
            if [ $? -eq 0 ]; then
                echo -e "\e[1;32mSUCESS\n\e[0m"
                ((i++))
                ((path++))
            else
                echo -e "\e[1;31mFAILURE\n\e[0m"
            fi
            rm bashtest/mysh.txt
            ((t++))
            ((patht++))

            echo -e "\e[1;37mTest n°$t (Change PATH for /bin/) :";
            echo -e 'setenv PATH /bin/\nls\npwd' | ./mysh > bashtest/mysh.txt 2>&1
            echo -e 'setenv PATH /bin/\nls\npwd' | tcsh > bashtest/tcsh.txt 2>&1
            sdiff -s bashtest/mysh.txt bashtest/tcsh.txt
            if [ $? -eq 0 ]; then
                echo -e "\e[1;32mSUCESS\n\e[0m"
                ((i++))
                ((path++))
            else
                echo -e "\e[1;31mFAILURE\n\e[0m"
            fi
            rm bashtest/tcsh.txt
            rm bashtest/mysh.txt
            ((t++))
            ((patht++))

            echo -e "\e[1;37mTest n°$t (Change PATH for random folder) :";
            echo -e 'setenv PATH /randomfolder/\nls\npwd' | ./mysh > bashtest/mysh.txt 2>&1
            sdiff -s bashtest/mysh.txt bashtest/cmdnotfound.txt
            if [ $? -eq 0 ]; then
                echo -e "\e[1;32mSUCESS\n\e[0m"
                ((i++))
                ((path++))
            else
                echo -e "\e[1;31mFAILURE\n\e[0m"
            fi
            rm bashtest/mysh.txt
            ((t++))
            ((patht++))

            echo -e "\e[1;37mTest n°$t (Exec command path) :";
            echo -e '/bin/ls' | ./mysh > bashtest/mysh.txt 2>&1
            echo -e '/bin/ls' | tcsh > bashtest/tcsh.txt 2>&1
            sdiff -s bashtest/mysh.txt bashtest/tcsh.txt
            if [ $? -eq 0 ]; then
                echo -e "\e[1;32mSUCESS\n\e[0m"
                ((i++))
                ((path++))
            else
                echo -e "\e[1;31mFAILURE\n\e[0m"
            fi
            rm bashtest/tcsh.txt
            rm bashtest/mysh.txt
            ((t++))
            ((patht++))

    echo -e "\n\n\e[1;36m-------------------------[BUILTIN ENV]-------------------------\n\e[0m";

        echo -e "\e[1;37mTest n°$t (env) :";
        echo -e "env" | ./mysh | grep -v "^_" | sort > bashtest/mysh.txt
        env | grep -v "^_" | sort > bashtest/tcsh.txt
        sdiff -s bashtest/mysh.txt bashtest/tcsh.txt
        if [ $? -eq 0 ]; then
            echo -e "\e[1;32mSUCESS\n\e[0m"
            ((i++))
            ((env++))
        else
            echo -e "\e[1;31mFAILURE\n\e[0m"
        fi
        rm bashtest/tcsh.txt
        rm bashtest/mysh.txt
        ((t++))
        ((envt++))

    echo -e "\n\n\e[1;36m-------------------------[BUILTIN UNSETENV]-------------------------\n\e[0m";

        echo -e "\e[1;37mTest n°$t (unsetenv) :";
        echo -e "env" | ./mysh | grep -v "^_" | sort > bashtest/mysh.txt
        env | grep -v "^_" | sort > bashtest/tcsh.txt
        sdiff -s bashtest/mysh.txt bashtest/tcsh.txt
        if [ $? -eq 0 ]; then
            rm bashtest/tcsh.txt
            rm bashtest/mysh.txt
            (echo -e "unsetenv OLDPWD" && echo -e "env") | ./mysh > bashtest/mysh.txt
            grep "OLDPWD=" bashtest/mysh.txt
            if [ $? -eq 0 ]; then
                echo -e "\e[1;31mFAILURE\n\e[0m"
            else
                echo -e "\e[1;32mSUCESS\n\e[0m"
                ((i++))
                ((unsetenv++))
            fi
        else
            echo -e "\e[1;31mFAILURE\n\e[0m"
        fi
        rm bashtest/mysh.txt
        ((t++))
        ((unsetenvt++))

    echo -e "\n\n\e[1;36m-------------------------[BUILTIN SETENV]-------------------------\n\e[0m";

        echo -e "\e[1;37mTest n°$t (setenv) :";
        (echo -e "setenv bonjour jesuisuntest" && echo -e "env") | ./mysh > bashtest/mysh.txt
        grep "bonjour=jesuisuntest" bashtest/mysh.txt > /dev/null
        if [ $? -eq 0 ]; then
            echo -e "\e[1;32mSUCESS\n\e[0m"
            ((i++))
            ((setenv++))
        else
            echo -e "\e[1;31mFAILURE\n\e[0m"
        fi
        rm bashtest/mysh.txt
        ((t++))
        ((setenvt++))

        echo -e "\e[1;37mTest n°$t (unsetenv with special value n°1) :";
        (echo -e "unsetenv") | ./mysh 2> bashtest/mysh.txt
        (echo -e "unsetenv") | tcsh 2> bashtest/tcsh.txt
        sdiff -s bashtest/mysh.txt bashtest/tcsh.txt
        if [ $? -eq 0 ]; then
            echo -e "\e[1;32mSUCESS\n\e[0m"
            ((i++))
            ((setenv++))
        else
            echo -e "\e[1;31mFAILURE\n\e[0m"
        fi
        rm bashtest/mysh.txt
        rm bashtest/tcsh.txt
        ((t++))
        ((setenvt++))

        echo -e "\e[1;37mTest n°$t (setenv with special value n°1) :";
        (echo -e "setenv 1bonjour jesuisuntest") | ./mysh 2> bashtest/mysh.txt
        (echo -e "setenv 1bonjour jesuisuntest") | tcsh 2> bashtest/tcsh.txt
        sdiff -s bashtest/mysh.txt bashtest/tcsh.txt
        if [ $? -eq 0 ]; then
            echo -e "\e[1;32mSUCESS\n\e[0m"
            ((i++))
            ((setenv++))
        else
            echo -e "\e[1;31mFAILURE\n\e[0m"
        fi
        rm bashtest/mysh.txt
        rm bashtest/tcsh.txt
        ((t++))
        ((setenvt++))

        echo -e "\e[1;37mTest n°$t (setenv with special value n°2) :";
        (echo -e "setenv bon/jour jesuisuntest") | ./mysh 2> bashtest/mysh.txt
        (echo -e "setenv bon/jour jesuisuntest") | tcsh 2> bashtest/tcsh.txt
        sdiff -s bashtest/mysh.txt bashtest/tcsh.txt
        if [ $? -eq 0 ]; then
            echo -e "\e[1;32mSUCESS\n\e[0m"
            ((i++))
            ((setenv++))
        else
            echo -e "\e[1;31mFAILURE\n\e[0m"
        fi
        rm bashtest/mysh.txt
        rm bashtest/tcsh.txt
        ((t++))
        ((setenvt++))

        echo -e "\e[1;37mTest n°$t (setenv with special value n°3) :";
        (echo -e "setenv b=onjour jesuisuntest") | ./mysh 2> bashtest/mysh.txt
        (echo -e "setenv b=onjour jesuisuntest") | tcsh 2> bashtest/tcsh.txt
        sdiff -s bashtest/mysh.txt bashtest/tcsh.txt
        if [ $? -eq 0 ]; then
            echo -e "\e[1;32mSUCESS\n\e[0m"
            ((i++))
            ((setenv++))
        else
            echo -e "\e[1;31mFAILURE\n\e[0m"
        fi
        rm bashtest/mysh.txt
        rm bashtest/tcsh.txt
        ((t++))
        ((setenvt++))

        echo -e "\e[1;37mTest n°$t (setenv with special value n°4) :";
        echo -e "setenv" | ./mysh | grep -v "^_" | sort > bashtest/mysh.txt
        env | grep -v "^_" | sort > bashtest/tcsh.txt
        sdiff -s bashtest/mysh.txt bashtest/tcsh.txt
        if [ $? -eq 0 ]; then
            echo -e "\e[1;32mSUCESS\n\e[0m"
            ((i++))
            ((setenv++))
        else
            echo -e "\e[1;31mFAILURE\n\e[0m"
        fi
        rm bashtest/tcsh.txt
        rm bashtest/mysh.txt
        ((t++))
        ((setenvt++))

        echo -e "\e[1;37mTest n°$t (setenv with special value n°5) :";
        (echo -e "setenv a b c") | ./mysh 2> bashtest/mysh.txt
        (echo -e "setenv a b c") | tcsh 2> bashtest/tcsh.txt
        sdiff -s bashtest/mysh.txt bashtest/tcsh.txt
        if [ $? -eq 0 ]; then
            echo -e "\e[1;32mSUCESS\n\e[0m"
            ((i++))
            ((setenv++))
        else
            echo -e "\e[1;31mFAILURE\n\e[0m"
        fi
        rm bashtest/mysh.txt
        rm bashtest/tcsh.txt
        ((t++))
        ((setenvt++))

    echo -e "\n\n\e[1;36m-------------------------[CD]-------------------------\n\e[0m";

        commands3=("cd" "cd bashtest" "cd .." "cd /" "cd ~" "cd .")
        descriptions2=("cd" "cd folder" "cd .." "cd /" "cd ~" "cd .")

        for ((index=0; index<${#commands3[@]}; index++)); do
            echo -e "\e[1;37mTest n°$t (${descriptions2[index]}) :";
            (echo -e "${commands3[index]}" && echo -e "pwd") | ./mysh > bashtest/mysh.txt
            (echo -e "${commands3[index]}" && echo -e "pwd") | tcsh > bashtest/tcsh.txt
            sdiff -s bashtest/mysh.txt bashtest/tcsh.txt
            if [ $? -eq 0 ]; then
                echo -e "\e[1;32mSUCESS\n\e[0m"
                ((i++))
                ((cd++))
            else
                echo -e "\e[1;31mFAILURE\n\e[0m"
            fi
            ((t++))
            ((cdt++))
        rm bashtest/tcsh.txt
        rm bashtest/mysh.txt
        done

        echo -e "\e[1;37mTest n°$t (cd -) :";
        (echo -e "pwd" && echo -e "cd .." && echo -e "pwd" && echo -e "cd -" && echo -e "pwd" && echo -e "cd -" && echo -e "pwd" && echo -e "cd" && echo -e "pwd" && echo -e "cd -" && echo -e "pwd" && echo -e "cd -" && echo -e "pwd" && echo -e "cd -" && echo -e "pwd" && echo -e "cd -" && echo -e "pwd" && echo -e "cd /" && echo -e "pwd" && echo -e "cd -" && echo "pwd" && echo -e "cd /bin/" && echo -e "pwd") | ./mysh > bashtest/mysh.txt
        (echo -e "pwd" && echo -e "cd .." && echo -e "pwd" && echo -e "cd -" && echo -e "pwd" && echo -e "cd -" && echo -e "pwd" && echo -e "cd" && echo -e "pwd" && echo -e "cd -" && echo -e "pwd" && echo -e "cd -" && echo -e "pwd" && echo -e "cd -" && echo -e "pwd" && echo -e "cd -" && echo -e "pwd" && echo -e "cd /" && echo -e "pwd" && echo -e "cd -" && echo "pwd" && echo -e "cd /bin/" && echo -e "pwd") | tcsh > bashtest/tcsh.txt
        sdiff -s bashtest/mysh.txt bashtest/tcsh.txt
        if [ $? -eq 0 ]; then
            echo -e "\e[1;32mSUCESS\n\e[0m"
            ((i++))
            ((cd++))
        else
            echo -e "\e[1;31mFAILURE\n\e[0m"
        fi
        rm bashtest/tcsh.txt
        rm bashtest/mysh.txt
        ((t++))
        ((cdt++))

    echo -e "\n\n\e[1;36m-------------------------[CD ERROR HANDLING]-------------------------\n\e[0m";

        commands6=("cd ffecvdzevvsd" "cd ./mysh" "cd abc def")
        descriptions6=("cd invalid folder" "cd executable" "cd too many argument")

        for ((index=0; index<${#commands6[@]}; index++)); do
            echo -e "\e[1;37mTest n°$t (${descriptions6[index]}) :";
            (echo -e "${commands6[index]}") | ./mysh 2> bashtest/mysh.txt
            (echo -e "${commands6[index]}") | tcsh 2> bashtest/tcsh.txt
            sdiff -s bashtest/mysh.txt bashtest/tcsh.txt
            if [ $? -eq 0 ]; then
                echo -e "\e[1;32mSUCESS\n\e[0m"
                ((i++))
                ((cd++))
            else
                echo -e "\e[1;31mFAILURE\n\e[0m"
            fi
            ((t++))
            ((cdt++))
        rm bashtest/tcsh.txt
        rm bashtest/mysh.txt
        done

    echo -e "\n\n\e[1;36m-------------------------[TABS AND SPACES]-------------------------\n\e[0m";

        commands5=("ls " "ls     " "ls   -a" "ls\t" "ls\t\t\t\t\t" "ls\t\t\t\t\t-a" "ls\t -a" "ls  \t\t \t -a" " " "\t" "ls . ..")
        descriptions4=("ls space" "ls spaces" "ls spaces -a" "ls tab" "ls tabs" "ls tabs -a" "ls tab space" "ls tabs spaces -a" "space" "tab" "ls 2 args")

        for ((index=0; index<${#commands5[@]}; index++)); do
            echo -e "\e[1;37mTest n°$t (${descriptions4[index]}) :";
            echo -e "${commands5[index]}" | ./mysh > bashtest/mysh.txt
            echo -e "${commands5[index]}" | tcsh > bashtest/tcsh.txt
            sdiff -s bashtest/mysh.txt bashtest/tcsh.txt
            if [ $? -eq 0 ]; then
                echo -e "\e[1;32mSUCESS\n\e[0m"
                ((i++))
                ((spaces++))
            else
                echo -e "\e[1;31mFAILURE\n\e[0m"
            fi
            rm bashtest/tcsh.txt
            rm bashtest/mysh.txt
            ((t++))
            ((spacest++))
        done

    echo -e "\n\n\e[1;36m-------------------------[ERROR HANDLING]-------------------------\n\e[0m";

        echo -e "\e[1;37mTest n°$t (Bin not compatible) :";
        (echo -e "bashtest/wa") | ./mysh 2> bashtest/mysh.txt
        sdiff -s bashtest/mysh.txt bashtest/wa.txt
        if [ $? -eq 0 ]; then
            echo -e "\e[1;32mSUCESS\n\e[0m"
            ((i++))
            ((error++))
        else
            echo -e "\e[1;31mFAILURE\n\e[0m"
        fi
        rm bashtest/mysh.txt
        ((t++))
        ((errort++))

        commands6=("bashtest/segv" "bashtest/valgrind_output")
        descriptions5=("SegFault with core dump" "exec a directory")

        for ((index=0; index<${#commands6[@]}; index++)); do
            echo -e "\e[1;37mTest n°$t (${descriptions5[index]}) :";
            echo -e "${commands6[index]}" | ./mysh 2> bashtest/mysh.txt
            echo -e "${commands6[index]}" | tcsh 2> bashtest/tcsh.txt
            sdiff -s bashtest/mysh.txt bashtest/tcsh.txt
            if [ $? -eq 0 ]; then
                echo -e "\e[1;32mSUCCESS\n\e[0m"
                ((i++))
                ((error++))
            else
                echo -e "\e[1;31mFAILURE\n\e[0m"
            fi
            rm bashtest/tcsh.txt
            rm bashtest/mysh.txt
            ((t++))
            ((errort++))
        done

    ((t--))
    echo -e "\n\n\e[1;37m--------------------------- RESULTS --------------------------\e[0m"
    echo -e "\e[1;37m|                                                            |\e[0m"
    if [ $i -eq $t ]; then
        echo -e "\e[1;37m|                      ALL TESTS PASSED                      |\e[0m"
    else
        echo -e "\e[1;37m                       $i / $t test passed\e[0m"
    fi
    echo -e "\e[1;37m|                                                            |\e[0m"
    echo -e "\e[1;37m--------------------------------------------------------------\e[0m"

}

test
make fclean