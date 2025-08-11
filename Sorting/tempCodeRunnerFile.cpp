 int p=lumuto_partition(a,l,h);
    QuickSort(a,l,p-1);
    QuickSort(a,p+1,h);