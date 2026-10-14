#include <stdio.h>

#define MAX_SHELF_WEIGHT 500.0

typedef struct {
    int pallet_id;
    float weight_kg;
    float temp_celsius;
} PalletItem;

typedef struct {
    int shelf_id;
    int is_cold_storage;
    float current_weight_kg;
} WarehouseShelf;

int kiem_tra_an_toan_nhap_kho(WarehouseShelf shelf, PalletItem item) {
    if (shelf.is_cold_storage == 1) {
        if (item.temp_celsius < -18.0 || item.temp_celsius > 5.0) {
            printf("[L?I KHO L?NH] Nhi?t d? b?o qu?n %.1f°C không d?t chu?n (-18°C d?n 5°C)!\n", item.temp_celsius);
            return 0;
        }
    }

    if (shelf.current_weight_kg + item.weight_kg > MAX_SHELF_WEIGHT) {
        printf("[L?I QUÁ T?I] T?ng tr?ng lu?ng sau khi nh?p (%.1f kg) vu?t gi?i h?n k? kho (500 kg)!\n", shelf.current_weight_kg + item.weight_kg);
        return 0;
    }

    return 1;
}

int main() {
    WarehouseShelf ke_lanh_101 = {101, 1, 400.0};
    PalletItem pallet_moi = {5001, 150.0, 12.0};

    printf("=== H? TH?NG GIÁM SÁT AN TOÀN NH?P KHO LOGISTICS ===\n");
    printf("Thông tin k? 101 : T?i tr?ng hi?n t?i = %.1f kg | Lo?i kho = %s\n", 
           ke_lanh_101.current_weight_kg, 
           ke_lanh_101.is_cold_storage ? "Kho L?nh" : "Kho Thu?ng");
    printf("Ki?n hàng nh?p   : Mã = %d | N?ng = %.1f kg | Nhi?t d? = %.1f°C\n",
           pallet_moi.pallet_id, pallet_moi.weight_kg, pallet_moi.temp_celsius);
    printf("----------------------------------------------------\n");

    int ket_qua = kiem_tra_an_toan_nhap_kho(ke_lanh_101, pallet_moi);

    if (ket_qua == 1) {
        printf("=> K?T QU?: [DUY?T] Ð? di?u ki?n nh?p kho!\n");
    } else {
        printf("=> K?T QU?: [T? CH?I] Vi ph?m quy d?nh an toàn luu kho!\n");
    }

    return 0;
}
