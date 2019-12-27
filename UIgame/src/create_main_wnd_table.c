#include "../include/create_main_wnd_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uiWindow *mainWnd;
static uiTableModelHandler handler;
static uiTableModel *model;

static int modelNumColums(uiTableModelHandler *handler, uiTableModel *model)
{
    return 4;
} 

static int modelNumRows(uiTableModelHandler *handler, uiTableModel *model)
{
    return 5;
}

static uiTableValueType modelColumnType(uiTableModelHandler *mh, uiTableModel *m, int column)
{
	return uiTableValueTypeString;
}

static uiTableValue *modelCellValue(uiTableModelHandler *mh, uiTableModel *m, int row, int col)
{
	char buf[256];
	return uiNewTableValueString(buf);
}

static void modelSetCellValue(uiTableModelHandler *mh, uiTableModel *m, int row, int col, const uiTableValue *val)
{
    return;
}


static int onClosing(uiWindow *w, void *data)
{
	uiQuit();
	return 1;
}

static int onShouldQuit(void *data)
{
	uiWindow *mainwin = uiWindow(data);

	uiControlDestroy(uiControl(mainwin));
	return 1;
}

uiControl *createMainWndTable(void)
{
    uiBox *hBox;
    uiTable *mainWndTable;
    uiTableParams params;
    uiGrid *grid; 
    //uiTableTextColumnOptionalParams textParams;

    hBox = uiNewHorizontalBox();
    grid = uiNewGrid();
    uiGridSetPadded(grid, 1);
    uiBoxAppend(hBox, uiControl(grid), 0);

    handler.NumColumns = modelNumColums;
    handler.NumRows = modelNumRows;
    handler.ColumnType = modelColumnType;
    handler.CellValue = modelCellValue;
    handler.SetCellValue = modelSetCellValue;

    model = uiNewTableModel(&handler);

    memset(&params, 0, sizeof(uiTableParams));
    params.Model = model;
    params.RowBackgroundColorModelColumn = 3; 
    mainWndTable = uiNewTable(&params);

    uiTableAppendTextColumn(mainWndTable, "Card", 0, uiTableModelColumnNeverEditable, NULL);

    uiGridAppend(grid, uiControl(mainWndTable), 50, 50, 50, 40, 1, uiAlignFill, 0, uiAlignFill);

    return uiControl(hBox);
}

int main()
{
	uiInitOptions options;
	const char *err;
	uiTab *tab;

	memset(&options, 0, sizeof (uiInitOptions));
	err = uiInit(&options);
	if (err != NULL) {
		fprintf(stderr, "error initializing libui: %s", err);
		uiFreeInitError(err);
		return 1;
	}

	mainWnd = uiNewWindow("libui Control Gallery", 1440, 1025, 1);
	uiWindowOnClosing(mainWnd, onClosing, NULL);
	uiOnShouldQuit(onShouldQuit, mainWnd);

	tab = uiNewTab();
	uiWindowSetChild(mainWnd, uiControl(tab));
	uiWindowSetMargined(mainWnd, 1);

    uiTabAppend(tab, "main window",  createMainWndTable());
	uiTabSetMargined(tab, 0, 1);

	uiControlShow(uiControl(mainWnd));
	uiMain();
	return 0;
}