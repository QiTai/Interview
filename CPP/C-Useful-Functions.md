## Useful Functions

### About String
+ strcpy
+ strtok
+ sscanf
```c
FILE *fp;
fseek(fp, 0, SEEK_SET);
while (!feof(fp)) {
    fgets(str1, LINE_SIZE, fp);
    strcpy(str2, str1);
    ptr = strtok(str1, "\r\t\n");
    if (sscanf(str2, "%s%lf%lf%lf%lf%lf%lf", name, &leftx, &bottomy, &width, &height, &cp, &res) > 4)
        count++;
}
```

### Sort
+ qsort()

### miscellany
+ calloc *difference between malloc and calloc is that calloc initialize the allocated space 0 while malloc doesn't*