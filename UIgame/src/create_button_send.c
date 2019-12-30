#include "../include/create_button_send.h"

int operations_rc = -1;

int check_entrys(uiWindow *operationWnd, void *entrySum, void *entryCardNum, char *curBalanse) 
{
    if (check_entry_sum(entrySum) == NO) {
        uiMsgBoxError(operationWnd, "Ошибка суммы.",
                      "Ошибка при вводе суммы, проверьте ввод.");
        operations_rc = SUM_ERROR;
        return NO;
    }

    if (checkEntryCard(entryCardNum) == NO) {
        uiMsgBoxError(operationWnd, "Ошибка карты.",
                      "Ошибка при вводе карты, проверьте ввод.");
        operations_rc = CARD_ERROR;
        return NO;
    }

    uiMsgBox(operationWnd, "Успешный перевод.", "Перевод проведен успешно.");
    operations_rc = OK;
    return OK;
}

uiButton *create_button_send() 
{

    send_button = uiNewButton("Перевести");

    return send_button;
}