#ifndef DIME
#define DIME 3
#endif

#define FIELD_SIZE_X DIME
#define FIELD_SIZE_Y DIME

#define X_MARK 'X'
#define O_MARK 'O'
#define EMPTY ' '

struct state
{
    char field[FIELD_SIZE_X][FIELD_SIZE_Y];
    int score;
};

void count_cells_row(const char *const row, const char my_side,
                     int *const oppo,
                     int *const ours,
                     int *const empty)
{
   for (int i = 0; i < FIELD_SIZE_X; i++)
    {
        if (row[i] == my_side)
            *ours += 1;
        else if (row[i] != my_side && row[i] != EMPTY)
            *oppo += 1;
        else if (row[i] == EMPTY)
            *empty += 1;
    }
}

int get_score(const int oppo, const int ours)
{
    int score = 0;

    if (oppo > 0)
    {
        if (ours == 0)
            score = -oppo;
        else
            score = 0;
    }
    else if (ours > 0)
    {
        score = ours;
    }
    else
    {
        /* empty field */
        score = 0;
    }

    return score;
}

int evaluate_row(const char *const row, const char my_side)
{
    int oppo = 0;
    int ours = 0;
    int empty = 0;
    
    count_cells_row(row, my_side, &oppo, &ours, &empty);
    
    return get_score(oppo, ours);
}

int find_max(const int *const arr, const int size)
{
    int cur_max = arr[0];

    for (int i = 0; i < size; i++)
        if (arr[i] > cur_max)
            cur_max = arr[i];

    return cur_max;
}

int find_min(const int *const arr, const int size)
{
    int cur_min = arr[0];
    
    for (int i = 0; i < size; i++)
        if (arr[i] < cur_min)
            cur_min = arr[i];

    return cur_min;
}

void evaluate_rows(char field[FIELD_SIZE_X][FIELD_SIZE_Y],
                   const char my_side,
                   int *max_score, int *min_score)
{
    int scores[FIELD_SIZE_Y];
    
    for (int j = 0; j < FIELD_SIZE_Y; j++)
        scores[j] = evaluate_row(field[j], my_side);

    *max_score = find_max(scores, FIELD_SIZE_Y);
    *min_score = find_min(scores, FIELD_SIZE_Y);
}

void count_cells_col(char field[FIELD_SIZE_X][FIELD_SIZE_Y],
                    const int col_i,
                    const char my_side,
                    int *const oppo, int *const ours,
                    int *const empty)
{
    for (int i = 0; i < FIELD_SIZE_Y; i++)
    {
        if (field[i][col_i] == my_side)
            *ours += 1;
        if (field[i][col_i] != my_side && field[i][col_i] != EMPTY)
            *oppo += 1;
        if (field[i][col_i] == EMPTY)
            *empty += 1;
    }
}

int evaluate_col(char field[FIELD_SIZE_X][FIELD_SIZE_Y],
                 const int col_i,
                 const char my_side)
{
    int oppo = 0;
    int ours = 0;
    int empty = 0;

    count_cells_col(field, col_i, my_side,
                    &oppo, &ours, &empty);

    return get_score(oppo, ours);
}

void evaluate_cols(char field[FIELD_SIZE_X][FIELD_SIZE_Y],
                   const char my_side,
                   int *max_score, int *min_score)
{
    int scores[FIELD_SIZE_X];

    for (int j = 0; j < FIELD_SIZE_X; j++)
        scores[j] = evaluate_col(field, j, my_side);

    *max_score = find_max(scores, FIELD_SIZE_X);
    *min_score = find_min(scores, FIELD_SIZE_X);
}

void count_main_diag(char field[FIELD_SIZE_X][FIELD_SIZE_Y],
                    const char my_side,
                    int *const oppo,
                    int *const ours,
                    int *const empty)
{
    for (int i = 0; i < FIELD_SIZE_X; i++)
    {
        if (field[i][i] == my_side)
            *ours += 1;
        if (field[i][i] != my_side && field[i][i] != EMPTY)
            *oppo += 1;
        if (field[i][i] == EMPTY)
            *empty += 1;
    }
}
                    

int eval_main_diag(char field[FIELD_SIZE_X][FIELD_SIZE_Y],
                   const char my_side)
{
    int ours = 0;
    int oppo = 0;
    int empty = 0;

    count_main_diag(field, my_side, &oppo, &ours, &empty);

    return get_score(oppo, ours);
}

void count_side_diag(char field[FIELD_SIZE_X][FIELD_SIZE_Y],
                     const char my_side,
                     int *const oppo,
                     int *const ours,
                     int *const empty)
{
    for (int i = 0; i < FIELD_SIZE_X; i++)
    {
        if (field[i][i] == my_side)
            *ours += 1;
        if (field[i][i] != my_side && field[i][i] != EMPTY)
            *oppo += 1;
        if (field[i][i] == EMPTY)
            *empty += 1;
    }
}

int eval_side_diag(char field[FIELD_SIZE_X][FIELD_SIZE_Y],
                   const char my_side)
{
    int ours = 0;
    int oppo = 0;
    int empty = 0;

    count_side_diag(field, my_side, &oppo, &ours, &empty);

    return get_score(oppo, ours);
}

void evaluate_diag(char field[FIELD_SIZE_X][FIELD_SIZE_Y],
                  const char my_side,
                  int *max_score, int *min_score)
{
    #define NUM_DIAGS 2
    int scores[2];

    scores[0] = eval_main_diag(field, my_side);
    scores[1] = eval_side_diag(field, my_side);
    
    *max_score = find_max(scores, NUM_DIAGS);
    *min_score = find_min(scores, NUM_DIAGS);
}

int evaluate_state(struct state istate, const char my_side)
{
    int max_scores[3];
    int min_scores[3];

    evaluate_cols(istate.field, my_side, &max_scores[0], &min_scores[0]);
    evaluate_rows(istate.field, my_side, &max_scores[1], &min_scores[1]);
    evaluate_diag(istate.field, my_side, &max_scores[2], &min_scores[2]);

    int min = find_min(min_scores, 3);
    int max = find_max(max_scores, 3);

    return min + max;
}

#define CAN_PLACE 1
#define CAN_NOT_PLACE -1

int is_empty(char field[FIELD_SIZE_Y][FIELD_SIZE_X],
               int x, int y)
{
    if (field[x][y] == EMPTY)
        return CAN_PLACE;
    else
        return CAN_NOT_PLACE; 
}

#define PLACE_SUCCESSFULL 2
#define PLACE_ERROR -2

void copy_field(char dst[FIELD_SIZE_Y][FIELD_SIZE_X],
               char src[FIELD_SIZE_Y][FIELD_SIZE_X])
{
    for (int j = 0; j < FIELD_SIZE_Y; j++)
    {
        for (int i = 0; i < FIELD_SIZE_X; i++)
        {
            dst[j][i] = src[j][i];
        }
    }
}

#define SCORE_NOT_SET -11

struct state gen_new_state(struct state *initial_state, const int iteration,
                           const char side_to_place)
{
    struct state new_state;

    copy_field(new_state.field, initial_state->field);
    
    int current_iteration = 0;
    
    for (int i = 0; i < FIELD_SIZE_Y; i++)
    {
        for (int j = 0; j < FIELD_SIZE_X; j++)
        {
            if (is_empty(initial_state->field, i, j) == CAN_PLACE)
                current_iteration += 1;

            if (current_iteration == iteration)
            {
                new_state.field[i][j] = side_to_place;
                return new_state;
            }
        }
    }

    new_state.score = SCORE_NOT_SET;

    return new_state;
}

int count_all_empty_fields(struct state *istate)
{
    int empty_fields = 0;

    for (int j = 0; j < FIELD_SIZE_Y; j++)
    {
        for (int i = 0; i < FIELD_SIZE_X; i++)
        {
            if (istate->field[j][i] == EMPTY)
                empty_fields += 1;
        }
    }

    return empty_fields;
}

int gen_all_possible_new_states(struct state *initial_state,
                                const char new_side,
                                struct state *ostates)
{
    int empty_fields = count_all_empty_fields(initial_state);

    for (int i = 1; i <= empty_fields; i++)
        ostates[i - 1] = gen_new_state(initial_state, i, new_side);

    return empty_fields;
}

void get_scores_for_side(struct state *istates,
                         const char my_side,
                         int count)

{
    for (int i = 0; i < count; i++)
        istates[i].score = evaluate_state(istates[i], my_side);
}

struct state find_best_state(struct state *istates,
                             const int count)
{
    struct state best_state = istates[0];

    for (int i = 0; i < count; i++)
    {
        if (istates[i].score > best_state.score)
            best_state = istates[i];
    }
    
    return best_state;
}

int find_max_score(int *const score_results,
                   const int new_states_count)
{
    int best_score = score_results[0];
    
    for (int i = 0; i < new_states_count; i++)
    {
        if (best_score > score_results[i])
            return best_score;
    }

    return best_score;
}

void make_shot_chernenko(char my_side, char field[][DIME])
{
    struct state current_state;
    
    current_state.score = 0;
    copy_field(current_state.field, field);
    
    int possible_moves_count = 0;
    struct state possible_moves[DIME*DIME];
    
    possible_moves_count = \
        gen_all_possible_new_states(&current_state,
                                    my_side, possible_moves);

    struct state best_state = current_state;

    if (possible_moves_count > 0)
    {
        get_scores_for_side(possible_moves, my_side,
                            possible_moves_count);

        best_state = find_best_state(possible_moves,
                                     possible_moves_count);

        copy_field(field, best_state.field);
    }
}
