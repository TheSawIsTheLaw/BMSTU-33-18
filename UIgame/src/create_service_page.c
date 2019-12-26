#include "../include/create_service_page.h"

static void cinema_onMsgBoxClicked(uiButton *b, void *data)
{
    uiMsgBox((uiWindow *)data,
             "Отличный день, чтобы сходить в кино!",
             "(хотя я бы на твоем месте зашел на вкладку \"баланс\" и задумался)");
}

static void restaurant_onMsgBoxClicked(uiButton *b, void *data)
{
    uiMsgBox((uiWindow *)data,
             "Проголодались?",
             "На Дауновской есть отличный МакДональдс, не теряйте свой шанс!");
}

static void shopping_onMsgBoxClicked(uiButton *b, void *data)
{
    uiMsgBox((uiWindow *)data,
             "Шоппинг - настоящее испытание",
             "Уверен, что твой кошелек выдержит его?");
}

static void quests_onMsgBoxClicked(uiButton *b, void *data)
{
    uiMsgBox((uiWindow *)data,
             "Квесты повсюду с нами!",
             "А как там, кстати, 7 лаба поживает?)");
}

static void theatres_onMsgBoxClicked(uiButton *b, void *data)
{
    uiMsgBox((uiWindow *)data,
             "Прекрасное место для прекрасных людей.",
             "Посетите \"Большой театр\", говорят, оно того стоит.");
}

static void journeys_onMsgBoxClicked(uiButton *b, void *data)
{
    uiMsgBox((uiWindow *)data,
             "Нью-Йорк, Лос-Анжелес, Флорида?...",
             "А как ты смотришь на ТюМеНь?)");
}

static void beauty_onMsgBoxClicked(uiButton *b, void *data)
{
    uiMsgBox((uiWindow *)data,
             "Ты и так самый красивый среди всех, кого я знаю!",
             "...Думаем мы с твоим кошельком...");
}

static void concerts_onMsgBoxClicked(uiButton *b, void *data)
{
    uiMsgBox((uiWindow *)data,
             "В преддверии нового года можно бесплатно сходить на утренник",
             "Так зачем тратить деньги?");
}

void createServicePage(uiTab *servTab, uiWindow *parent)
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
    uiButtonOnClicked(btn, cinema_onMsgBoxClicked, parent);
    uiGridAppend(grid, uiControl(btn), 20, 25, 25, 12,
                 1, uiAlignFill, 0, uiAlignFill);

    btn = (uiNewButton("Ресторан"));
    uiButtonOnClicked(btn, restaurant_onMsgBoxClicked, parent);
    uiGridAppend(grid, uiControl(btn), 20, 40, 25, 12, 1, uiAlignFill, 0, uiAlignFill);

    btn = (uiNewButton("Шопинг"));
    uiButtonOnClicked(btn, shopping_onMsgBoxClicked, parent);
    uiGridAppend(grid, uiControl(btn), 20, 55, 25, 12, 1, uiAlignFill, 0, uiAlignFill);

    btn = (uiNewButton("Квесты"));
    uiButtonOnClicked(btn, quests_onMsgBoxClicked, parent);
    uiGridAppend(grid, uiControl(btn), 20, 70, 25, 12, 1, uiAlignFill, 0, uiAlignFill);

    btn = (uiNewButton("Театры"));
    uiButtonOnClicked(btn, theatres_onMsgBoxClicked, parent);
    uiGridAppend(grid, uiControl(btn), 45, 25, 25, 12, 1, uiAlignFill, 0, uiAlignFill);

    btn = (uiNewButton("Путешествия"));
    uiButtonOnClicked(btn, journeys_onMsgBoxClicked, parent);
    uiGridAppend(grid, uiControl(btn), 45, 40, 25, 12, 1, uiAlignFill, 0, uiAlignFill);

    btn = (uiNewButton("Красота"));
    uiButtonOnClicked(btn, beauty_onMsgBoxClicked, parent);
    uiGridAppend(grid, uiControl(btn), 45, 55, 25, 12, 1, uiAlignFill, 0, uiAlignFill);

    btn = (uiNewButton("Концерты"));
    uiButtonOnClicked(btn, concerts_onMsgBoxClicked, parent);
    uiGridAppend(grid, uiControl(btn), 45, 70, 25, 12, 1, uiAlignFill, 0, uiAlignFill);
}
