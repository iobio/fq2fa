#!/bin/bash

FQ2FA=/home/iobio/minion/tools/fq2fa/build/src/fq2fa

arg=""

if [[ $# -eq 0 ]];

        then
                eval "$FQ2FA <&0"
        else
                for i in $@; do
                        new_arg="<(curl -s \"$i\")"
                        arg="$arg $new_arg"
                done
                eval "$FQ2FA $arg"
fi
