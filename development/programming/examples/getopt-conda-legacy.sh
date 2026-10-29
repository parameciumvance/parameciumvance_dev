#!/usr/bin/env bash
set -e #有錯時停止腳本
#PATH=.:$PATH

#切換conda環境所需(子shell不會繼承parent shell定義的函數)
. $(dirname $CONDA_EXE)/../etc/profile.d/conda.sh
conda activate base

#參數解析
TEMP=`getopt -o ab:c:: --long a-long,b-long:,c-long:: --name "$0" -- "$@"`
if [ $? != 0 ] ; then echo "Terminating..." >&2 ; exit 1 ; fi
eval set -- "$TEMP"
echo ARGS: $TEMP

while true ; do
    case "$1" in
        -a|--a-long) echo "Option a" ; shift ;;
        -b|--b-long) echo "Option b, argument \`$2'" ; shift 2 ;;
        -c|--c-long)
            # c has an optional argument. As we are in quoted mode,
            # an empty parameter will be generated if its optional
            # argument is not found.
            case "$2" in
                "") echo "Option c, no argument"; shift 2 ;;
                *)  echo "Option c, argument \`$2'" ; shift 2 ;;
            esac ;;
        --) shift ; break ;;
        *) echo "Internal error!" ; exit 1 ;;
    esac
done
echo "Remaining arguments:"
for arg do
   echo '--> '"\`$arg'" ;
done
