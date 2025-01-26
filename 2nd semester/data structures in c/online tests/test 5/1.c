    #include <stdio.h>
    #include <stdlib.h>
    void main()
    {
    char i, a[125];
    for(i=0; i<125; i++) a[i]=i;
    for(i=70; i<80; i++) printf("%5d",a[i]);
    printf("\n");
    for(i=70; i<80; i++) printf("%5c",a[i]);
    }
