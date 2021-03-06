#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "warehouse_model.h"

void init_warehouse(Warehouse *pwarehouse) {
    pwarehouse->amount = 0;
}

Good *look_up_good(Warehouse *pwarehouse, const char *type) {
    int length = pwarehouse->amount;
    for (int i = 0; i < length; i++) {
        Good *pgood = &(pwarehouse->good_list[i]);
        if (strcmp(pgood->type, type) == 0) {
            return pgood;
        }
    }
    return NULL;
}

static int will_full(Warehouse *pwarehouse, const char *type, int amount) {
    Good *pgood = look_up_good(pwarehouse, type);
    if (pgood) {
        return pgood->amount + amount > INT_MAX;
    } else {
        return pwarehouse->amount + 1 > MAX_KIND_OF_TYPE;
    }
}

static int will_empty(Warehouse *pwarehouse, const char *type, int amount) {
    Good *pgood = look_up_good(pwarehouse, type);
    if (pgood) {
        return pgood->amount - amount < 0;
    } else {
        return 1;
    }
}

ware_state store_good(Warehouse *pwarehouse, const char *type, int amount) {
    Good *pgood = look_up_good(pwarehouse, type);
    if (will_full(pwarehouse, type, amount)) {
        return FULL_ERROR;
    } else if (pgood != NULL) {
        pgood->amount += amount;
        return FINE;
    } else {
        Good *pnewgood = &pwarehouse->good_list[(pwarehouse->amount)++];
        pnewgood->amount = amount;
        strcpy(pnewgood->type, type);
        return FINE;
    }
}

ware_state discharge_good(Warehouse *pwarehouse, const char *type, int amount) {
    if (will_empty(pwarehouse, type, amount)) {
        return EMPTY_ERROR;
    } else {
        Good *pgood = look_up_good(pwarehouse, type);
        pgood->amount -= amount;
        return FINE;
    }
}

void clean_ware_house(Warehouse *pwarehouse) {
    pwarehouse->amount = 0;
}

void load_from_file(Warehouse *pwarehouse, const char *filename) {
    clean_ware_house(pwarehouse);
    FILE *fp = fopen(filename, "r");
    char type[MAX_TYPE_LENGTH] = {0};
    int amount = 0;
    int state = fscanf(fp, "%s ## %d ###", type, &amount);
    while (state != EOF) {
        store_good(pwarehouse, type, amount);
        state = fscanf(fp, "%s ## %d ###", type, &amount);
    }
    fclose(fp);
}

void save_data(Warehouse *pwarehouse, const char *filename) {
    FILE *fp = fopen(filename, "w");
    for (int i = 0; i < pwarehouse->amount; i++) {
        const Good *good = &pwarehouse->good_list[i];
        fprintf(fp, "%s ## %d ###", good->type, good->amount);
    }
    putc('\n', fp);
    fclose(fp);
}
