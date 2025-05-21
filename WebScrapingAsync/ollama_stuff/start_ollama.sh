#!/bin/sh

ollama server &

sleep 10

ollama pull llama3.2

python ./src/main.py