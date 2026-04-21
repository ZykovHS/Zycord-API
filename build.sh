#!/bin/bash
mkdir -p run/sockets
make clean
make all
chmod +x engine_bin infra_bin
