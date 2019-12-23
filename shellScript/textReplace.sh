#!/bin/bash

cat demo.txt
sed -i -e 's/Calcutta/Kalicut/g' -e 's/University/College/g' demo.txt
cat demo.txt
