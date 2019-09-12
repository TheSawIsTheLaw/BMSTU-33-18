#define FULL_FILE_SIZE 31887659 //изменить !
#define CLEAN_FILE_SIZE 50000 // изменить!

int get_file_size(FILE* f)
{
	fseek(f, 0, SEEK_END);
	int size = ftell(f) / (2 * sizeof(int));
	return size;
}

void make_array(int actor_to_actor_arr[][2], FILE* f, int size)
{
	fread(&actor_to_actor_arr, sizeof(int) * 2, size, f);
}

void write_clean_array(int actor_to_actor_arr[][2], int size, FILE* actors_file)
{
	my_sort(actor_to_actor_arr, 0, size - 1, 0);

	fwrite(actor_to_actor_arr[0], sizeof(int) * 2, 1, actors_file);
	for (int i = 1; i < size; i++)
	{
		if (((actor_to_actor_arr[i][0] == actor_to_actor_arr[i][1]) ||
		(actor_to_actor_arr[i][0] == actor_to_actor_arr[i - 1][0] &&
		actor_to_actor_arr[i][1] == actor_to_actor_arr[i - 1][1])))
		{
			printf("1  ");
			fwrite(actor_to_actor_arr[i], sizeof(int) * 2, 1, actors_file);
		}
	}
}
