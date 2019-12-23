#!/bin/bash

echo 'enter a string'
read string

echo -n $string | wc -m
