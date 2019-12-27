#include "../include/create_account_page.h"
#include <string.h>

static int modelNumColums()
{
    return 2;
}

static int modelNumRows()
{
    return 5;
}

static uiTableValueType modelColumnType()
{
    return uiTableValueTypeString;
}

static uiTableValue *modelCellValue(int row, int col)
{
    char buf[256];

    if (col == 0)
    {
        switch (row)
        {
            case 0:
                strcpy(buf, "\n\n\t         Oleneff Platinum\n\n");
                break;
            case 1:
                strcpy(buf, "\n\n\t\t   Oleneff Black\n\n");
                break;
            case 2:
                strcpy(buf, "\n\n\t\t       Visa Gold\n\n");
                break;
            case 3:
                strcpy(buf, "\n\n\t    Master Card Business\n\n");
                break;
            case 4:
                strcpy(buf, "\n\n\t\t     Oleneff Kids\n\n");
                break;
        }

        return uiNewTableValueString(buf);
    }

    if (col == 1)
    {
        switch (row)
        {
            case 0:
                strcpy(buf, "\n\n\t\t      37456,34 р.\n\n");
                break;
            case 1:
                strcpy(buf, "\n\n\t\t      11400,79 р.\n\n");
                break;
            case 2:
                strcpy(buf, "\n\n\t\t      14374,23 р.\n\n");
                break;
            case 3:
                strcpy(buf, "\n\n\t\t       3987.67 р.\n\n");
                break;
            case 4:
                strcpy(buf, "\n\n\t\t       7984.32 р.\n\n");
                break;
        }

        return uiNewTableValueString(buf);
    }

    return uiNewTableValueString(buf);
}


void createAccountPage(uiTab *mainTab, uiWindow *wndMain)
{
    uiBox *accountPage = uiNewVerticalBox();
    uiTabAppend(mainTab, "Информация об аккаунте", uiControl(accountPage));

    uiTableParams params;
    uiTableModelHandler handler;
    uiTableModel *model;
    uiTable *accTable;


    handler.NumColumns = modelNumColums;
    handler.NumRows = modelNumRows;
    handler.ColumnType = modelColumnType;

    model = uiNewTableModel(&handler);

    params.Model = model;
    params.RowBackgroundColorModelColumn = 2;
    accTable = uiNewTable(&params);

    uiTableAppendTextColumn(accTable, "\n\t\t\tКарта \t\t\t\n", 0, uiTableModelColumnNeverEditable, NULL);
    uiTableAppendTextColumn(accTable, "\n\t\t\t Баланс          \t\t\n", 1, uiTableModelColumnNeverEditable, NULL);


}

