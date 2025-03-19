#!/bin/bash
cut -d: -f 1| sed -n 2~2p | rev | sort -r | sed -n "24,42p" | tr "\n" ","| sed -e "s/,/, /g"| sed -e "s/, $/.\n/g"   
