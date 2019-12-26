#include "../include/create_service_page.h"

// void uiGridAppend(uiGrid *g, uiControl *c, int left,
// int top, int xspan, int yspan, int hexpand, uiAlign halign,
// int vexpand, uiAlign valign)

void createServicePage(uiTab *servTab)
{
    uiBox *servPage = uiNewHorizontalBox();
    uiBoxSetPadded(servPage, 1);
    uiTabAppend(servTab, "Сервисы", uiControl(servPage));
    uiTabSetMargined(servTab, 5, 1);

    uiGrid *grid = uiNewGrid();
    uiGridSetPadded(grid, 1);
    uiBoxAppend(servPage, uiControl(grid), 0);

    uiLabel *free_space = uiNewLabel("");
    uiGridAppend(grid, uiControl(free_space), 0, 0, 20, 200,
                 1, uiAlignCenter, 0, uiAlignCenter);

    // здесь должен быть поиск....

    uiButton *btn;
    btn = (uiNewButton("Kино"));
    uiGridAppend(grid, uiControl(btn), 20, 25, 25, 12,
                 1, uiAlignFill, 0, uiAlignFill);

    btn = (uiNewButton("Ресторан"));
    uiGridAppend(grid, uiControl(btn), 20, 40, 25, 12, 1, uiAlignFill, 0, uiAlignFill);

    btn = (uiNewButton("Шопинг"));
    uiGridAppend(grid, uiControl(btn), 20, 55, 25, 12, 1, uiAlignFill, 0, uiAlignFill);

    btn = (uiNewButton("Квесты"));
    uiGridAppend(grid, uiControl(btn), 20, 70, 25, 12, 1, uiAlignFill, 0, uiAlignFill);

    btn = (uiNewButton("Театры"));
    uiGridAppend(grid, uiControl(btn), 45, 25, 25, 12, 1, uiAlignFill, 0, uiAlignFill);

    btn = (uiNewButton("Путешествия"));
    uiGridAppend(grid, uiControl(btn), 45, 40, 25, 12, 1, uiAlignFill, 0, uiAlignFill);

    btn = (uiNewButton("Красота"));
    uiGridAppend(grid, uiControl(btn), 45, 55, 25, 12, 1, uiAlignFill, 0, uiAlignFill);

    btn = (uiNewButton("Концерты"));
    uiGridAppend(grid, uiControl(btn), 45, 70, 25, 12, 1, uiAlignFill, 0, uiAlignFill);
}
