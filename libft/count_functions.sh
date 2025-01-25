#!/bin/bash
YELLOW='\033[0;33m'
NC='\033[0m'
cnt=$(ls */*.c | wc -l)
cnt=$((cnt + 2))
echo -e "number of functions : ${YELLOW}$cnt${NC}"
