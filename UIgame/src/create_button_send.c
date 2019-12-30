#include "../include/create_button_send.h"

uiButton *send_button;

int operations_rc = -1;

void check_entrys(uiButton *b, void *data) {
    printf("%p ETO BLIN YA DAL (vo dal)\n", data);

    uiWindow *errWnd = *((uiWindow **)data + 3);
    char **temp = (char **)data;

    printf("1->%s 2->%s 3->%s\n", temp[0], temp[1], temp[2]);

    if (check_entry_sum(temp[0]) == NO) {
        uiMsgBoxError(errWnd, "Ошибка суммы.",
                      "Ошибка при вводе суммы, проверьте ввод.");
        operations_rc = SUM_ERROR;
        return;
    }

    if (checkEntryCard(temp[1]) == NO) {
        uiMsgBoxError(errWnd, "Ошибка карты.",
                      "Ошибка при вводе карты, проверьте ввод.");
        operations_rc = CARD_ERROR;
        return;
    }

    uiMsgBox(errWnd, "Успешный перевод.", "Перевод проведен успешно.");
    operations_rc = OK;
    return;
}

uiButton *create_button_send(uiWindow *wnd, uiEntry *entry_sum,
                             uiEntry *entry_cardnum, char *amount) {
    void *entrys[4];

    entrys[0] = uiEntryText(entry_sum);
    entrys[1] = uiEntryText(entry_cardnum);
    entrys[2] = amount;
    entrys[3] = wnd;

    printf("1->%s 2->%s 3->%s\n", (char *)entrys[0], (char *)entrys[1],
           (char *)entrys[2]);

    uiButtonOnClicked(send_button, check_entrys, entrys);

    return send_button;
}