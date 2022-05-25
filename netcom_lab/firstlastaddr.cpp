#include <stdio.h>
#include <math.h>
using namespace std;
void printad(long int l){
    int x, y, z, t;
    t = l & 255;
    l = l >> 8;
    z = l & 255;
    l = l >> 8;
    y = l & 255;
    x = l >> 8;
    printf("Addr-> %d.%d.%d.%d\n\n", x, y, z, t);
}
int main(){
    int x, y, z, t, sub;
    long int addr, subnet, antisub, fadr, ladr;
    printf("IPv4 Address: ");
    scanf("%d.%d.%d.%d/%d", &x, &y, &z, &t, &sub);
    addr = x;
    addr = addr << 8;
    addr |= y;
    addr = addr << 8;
    addr |= z;
    addr = addr << 8;
    addr |= t;
    printf("IP:\n");
    printad(addr);
    subnet = pow(2, 32) - pow(2, 32 - sub);
    antisub = pow(2, 32 - sub) - 1;
    printf("Subnet mask:\n");
    printad(subnet);
    fadr = addr & subnet;
    ladr = addr | antisub;
    printf("First:\n");
    printad(fadr);
    printf("Last:\n");
    printad(ladr);
    printf("Total addresses: %d\n", (int)pow(2, 32 - sub));
    return 0;
}