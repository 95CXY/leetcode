
解题模板:  hash + prefix


xxxxxxx [ixxxxj] xxxxx

假设原数组对p 取模的值为r0，想要移除最短的子数组之后能够被p整除，则 Sum[i:j] % p == r0;

前缀和 prefixSum[0:j] % p = r; 则 prefixSum[0: i-1] % p = r - r0;

```
sum[i: j] = prefixSum[j] - prefixSum[i-1]
   r0           r
prefixSum[i - 1] % p = (prefixSum[j] % p) - (prefixSum[i: j] % p);
```

我们用指针j遍历原数组，即可求得当前的r，r0 已知，则即可通过 (r - r0) 求得i的索引下标， i = hashtable[r - r0] + 1,

值得注意的是，我们用 hashtable 来记录当前 sum[0:j] % p 时 j 的值，hashtable[r] = j; 随着j 的移动，hashtable会保存对p去模时较大的下标。


**值得注意的点：**

1. 前缀和 % p == 0 的初始索引为-1;
2. r - r0 < 0 时，hashtable 中将取不到下标，则应把 r - r0 + p 作为 key;  (r - r0) % p == (r - r0 + p) % p
3. 如果数组元素的值比较大，则可能存在累加越界的问题，我们想要求的是 prefixSum % p, 可以先取模在累加。

















