#include "../include/create_account_tab.h"

static uiTableModelHandler handler;
static uiTableModel *model;

static int modelNumColums(uiTableModelHandler *handler, uiTableModel *model)
{
    return COLS_TOTAL;
}

static int modelNumRows(uiTableModelHandler *handler, uiTableModel *model)
{
    return CARDS_TOTAL;
}

static uiTableValueType modelColumnType(uiTableModelHandler *handler, uiTableModel *model, int column)
{
    return uiTableValueTypeString;
}

static uiTableValue *modelCellValue(uiTableModelHandler *handler, uiTableModel *model, int row, int col)
{
    char buf[256];

    if (col == 0)
    {
        switch (row)
        {
            case 0:
                strcpy(buf, "\n\n\t        Oleneff Platinum\n\n");
                break;
            case 1:
                strcpy(buf, "\n\n\t\t Oleneff Black\n\n");
                break;
            case 2:
                strcpy(buf, "\n\n\t\t    Visa Gold\n\n");
                break;
            case 3:
                strcpy(buf, "\n\n\t  Master Card Business\n\n");
                break;
            case 4:
                strcpy(buf, "\n\n\t\t   Oleneff Kids\n\n");
                break;
        }

        return uiNewTableValueString(buf);
    }

    if (col == 1)
    {
        switch (row)
        {
            case 0:
                strcpy(buf, "\n\n\t\t 37456.34 р.\n\n");
                break;
            case 1:
                strcpy(buf, "\n\n\t\t 11400.79 р.\n\n");
                break;
            case 2:
                strcpy(buf, "\n\n\t\t 14374.23 р.\n\n");
                break;
            case 3:
                strcpy(buf, "\n\n\t\t 3987.67 р.\n\n");
                break;
            case 4:
                strcpy(buf, "\n\n\t\t 7984.32 р.\n\n");
                break;
        }

        return uiNewTableValueString(buf);
    }

    return uiNewTableValueString(buf);
}

uiControl *createAccTable(void)
{
    uiBox *hBox;
    uiTable *accTable;
    uiTableParams params;
    uiGrid *grid;
    uiLabel *space, *achievements;

    hBox = uiNewHorizontalBox();
    grid = uiNewGrid();
    uiGridSetPadded(grid, 1);
    uiBoxAppend(hBox, uiControl(grid), 0);

    handler.NumColumns = modelNumColums;
    handler.NumRows = modelNumRows;
    handler.ColumnType = modelColumnType;
    handler.CellValue = modelCellValue;

    model = uiNewTableModel(&handler);

    memset(&params, 0, sizeof(uiTableParams));
    params.Model = model;
    params.RowBackgroundColorModelColumn = 2;
    accTable = uiNewTable(&params);

    uiTableAppendTextColumn(accTable, "\n\t\t Карта \t\t\n", 0, uiTableModelColumnNeverEditable, NULL);
    uiTableAppendTextColumn(accTable, "\n\t\t Баланс\t\t\n", 1, uiTableModelColumnNeverEditable, NULL);

    space = uiNewLabel("");
    achievements = uiNewLabel("\t\t\t\tДостижения:\n\n\t\t\t✔ Консоль mode!\n\n\t\t\t✔ Сын маминой подруги...\n\n\t\t\t✔ Купил сыну велосипед\n\n\t\t\t✔ Много денег!\n\n\t\t\t✔ Сделать uigame\n\n\n\n\t\t\t     Не разблокировано:\n\n\t\t\tX Сдать физику\n\n\t\t\tX Стать хорошим програмистом");
    uiGridAppend(grid, uiControl(space), 0, 5, 55, 13, 1, uiAlignCenter, 0, uiAlignCenter);
    uiGridAppend(grid, uiControl(achievements), 40, 30, 45, 40, 1, uiAlignCenter, 0, uiAlignCenter);
    uiGridAppend(grid, uiControl(accTable), 5, 30, 40, 77, 1, uiAlignFill, 0, uiAlignFill);

    return uiControl(hBox);
}
