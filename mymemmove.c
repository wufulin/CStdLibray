#include <stdio.h>
#include <string.h>

void *mymemmove(void *dest, const void *src, size_t n)
{
  char temp[n];
  int i;
  char *d = dest;
  const char *s = src;

  for(i=0;i<n;i++)
    temp[i] = s[i];
  for(i=0;i<n;i++)
    d[i]=temp[i];

  return dest;
}

void *mymemcpy(void *dest, const void *src, size_t n)
{
  char *d = dest;
  const char *s = src;
  int *di;
  const int *si;
  int r = n % 4;
  while(r--)
    *d++ = *s++;
  di = (int *)d;
  si = (const int *)s;
  n /= 4;
  while(n--)
    *di++ = *si++;

  return dest;
}

int main(void)
{
  char buf[20] = "hello world\n";
  printf("%lu %lu", sizeof(buf)/sizeof(char), strlen(buf));
  //memcpy(buf+1, buf, 13);
  memmove(buf+1, buf, 13);
  printf("%s", buf);
  return 0;
}
