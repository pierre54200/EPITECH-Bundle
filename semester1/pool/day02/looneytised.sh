#!/bin/bash
cat Day02/passwd | grep "theo1" | sed -e 's/theo1/Wile E. Coyote/'
cat Day02/passwd | grep "steven1"| sed -e 's/steven1/Daffy Duck/'
cat Day02/passwd | grep "arnaud1"| sed -e 's/arnaud1/Porky Pig/'
cat Day02/passwd | grep "pierre-jean" | sed -e 's/pierre-jean/Marvin the Martian/'

