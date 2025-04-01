#include "../cube.h"
#include <stdio.h>

struct img
	{
		void *img;
		char *addr;
		int bits_per_pixel;
		int line_length;
		int endian;
	} img;

/*int	main(void)
{
	//void *tx;
	void *mlx;
	struct img txt;

	int sz = 64;
	int	sz2 = 64;
	mlx = mlx_init();
	txt.img = mlx_xpm_file_to_image(mlx,
		"./img/door_open.xpm", &sz, &sz2);
	//txt->img = tx;
	if (txt.img == NULL)
	{
		printf("Error\n");
		return (1);
	}
	txt.addr = mlx_get_data_addr(&txt.img,
		&txt.bits_per_pixel, &txt.line_length, &txt.endian);
	if (txt.addr == NULL)
	{
		printf("Error\n");
		return (1);
	}
	int i = 0;
	int j;
	while(++i < 64)
	{
		j = 0;
		while(++j < 64)
		{
			unsigned int color = *(unsigned int *)(txt.addr + (i * txt.line_length + j * (txt.bits_per_pixel / 8)));
            unsigned char r = (color >> 16) & 0xFF; // Composante rouge
            unsigned char g = (color >> 8) & 0xFF;  // Composante verte
            unsigned char b = color & 0xFF;         // Composante bleue
            printf("Pixel (%d, %d): R=%u, G=%u, B=%u\n", i, j, r, g, b);
		}
	}
}*/

int	main(void)
{
    void *mlx;
    struct img txt;

    int sz = 64;
    int sz2 = 64;

    // Initialisation de MiniLibX
    mlx = mlx_init();
    if (!mlx)
    {
        fprintf(stderr, "Error: Failed to initialize MiniLibX\n");
        return (1);
    }

    // Chargement de l'image
    txt.img = mlx_xpm_file_to_image(mlx, "./img/door_open.xpm", &sz, &sz2);
    if (!txt.img)
    {
        fprintf(stderr, "Error: Failed to load XPM file\n");
        return (1);
    }

    // Récupération de l'adresse des données de l'image
    txt.addr = mlx_get_data_addr(txt.img, &txt.bits_per_pixel, &txt.line_length, &txt.endian);
    if (!txt.addr)
    {
        fprintf(stderr, "Error: Failed to get data address\n");
        return (1);
    }

    // Parcours des pixels
    int i = -1;
    int j;
    while (++i < sz)
    {
        j = -1;
        while (++j < sz2)
        {
            unsigned int color = *(unsigned int *)(txt.addr + (i * txt.line_length + j * (txt.bits_per_pixel / 8)));
            unsigned char a = (color >> 24) & 0xFF; // Composante alpha
			unsigned char r = (color >> 16) & 0xFF; // Composante rouge
            unsigned char g = (color >> 8) & 0xFF;  // Composante verte
            unsigned char b = color & 0xFF;         // Composante bleue
            printf("Pixel (%d, %d): R=%u, G=%u, B=%u, A=%u\n", i, j, r, g, b, a);
        }
    }
    return (0);
}