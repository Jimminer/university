#!/bin/bash

echo -e -n "1. Emfanisi imerominias\n2. Emfanisi oras\n3. Emfanisi onomatos xristi\nGia eksodo patiste (e/E)\n\nParakalo epilekste: "
read selection

case $selection in
    "1")
        echo "I imerominia einai: $(date "+%d/%m/%Y")"
    ;;

    "2")
        echo "I ora einai: $(date "+%H:%M")"
    ;;

    "3")
        echo "To onoma xristi einai: $USER"
    ;;

    [Ee])
        echo "Exiting..."
        exit 1
    ;;

    *)
        echo "Invalid selection"
    ;;
esac