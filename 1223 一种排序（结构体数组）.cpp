#include <stdio.h>
#include <stdlib.h>

struct Rectangle{
    int id;
    int l;
    int w;
};

int compare(const void *a, const void *b) {
    struct Rectangle *r1 = (struct Rectangle *)a;
    struct Rectangle *r2 = (struct Rectangle *)b;
    
    if (r1->id != r2->id) return r1->id - r2->id;
    if (r1->l != r2->l) return r1->l - r2->l;
    return r1->w - r2->w;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int m;
        scanf("%d", &m);
        
        struct Rectangle rects[1000];
        int count = 0;

        for (int i = 0; i < m; i++) {
            int id, a, b;
            scanf("%d %d %d", &id, &a, &b);

            int l = (a >= b) ? a : b;
            int w = (a >= b) ? b : a;

            int found = 0;
            for (int j = 0; j < count; j++) {
                if (rects[j].id == id && rects[j].l == l && rects[j].w == w) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                rects[count].id = id;
                rects[count].l = l;
                rects[count].w = w;
                count++;
            }
        }
        
        qsort(rects, count, sizeof(struct Rectangle), compare);

        for (int i = 0; i < count; i++) {
            printf("%d %d %d\n", rects[i].id, rects[i].l, rects[i].w);
        }

    }

}
