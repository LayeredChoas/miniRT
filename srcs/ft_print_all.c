#include "./../include/ft_minirt.h"

void    ft_print_sphere(t_sphere sp)
{
    ft_putstr("sp ");
    ft_putnbr(sp.cor.x, 1);
    ft_putstr(",");
    ft_putnbr(sp.cor.y, 1);
    ft_putstr(",");
    ft_putnbr(sp.cor.z, 1);
    ft_putstr("  ");
    ft_putnbr(sp.d, 1);
    ft_putstr("  ");
    ft_putnbr(sp.col.x, 1);
    ft_putstr(",");
    ft_putnbr(sp.col.y, 1);
    ft_putstr(",");
    ft_putnbr(sp.col.z, 1);
    ft_putstr("\n");
}

void    ft_print_square(t_square sq)
{
    ft_putstr("sq ");
    ft_putnbr(sq.cor.x, 1);
    ft_putstr(",");
    ft_putnbr(sq.cor.y, 1);
    ft_putstr(",");
    ft_putnbr(sq.cor.z, 1);
    ft_putstr("  ");
    /*
    ft_putnbr(sq.nor.x, 1);
    ft_putstr(",");
    ft_putnbr(sq.nor.y, 1);
    ft_putstr(",");
    ft_putnbr(sq.nor.z, 1);
    */
    printf("%f\t%f\t%f\n", sq.nor.x, sq.nor.y, sq.nor.z);
    ft_putstr("  ");
    ft_putnbr(sq.s, 1);
    ft_putstr("  ");
    ft_putnbr(sq.col.x, 1);
    ft_putstr(",");
    ft_putnbr(sq.col.y, 1);
    ft_putstr(",");
    ft_putnbr(sq.col.z, 1);
    ft_putstr("\n");
}

void    ft_print_plane(t_plane pl)
{
    ft_putstr("pl ");
    ft_putnbr(pl.cor.x, 1);
    ft_putstr(",");
    ft_putnbr(pl.cor.y, 1);
    ft_putstr(",");
    ft_putnbr(pl.cor.z, 1);
    ft_putstr("  ");
    ft_putnbr(pl.nor.x, 1);
    ft_putstr(",");
    ft_putnbr(pl.nor.y, 1);
    ft_putstr(",");
    ft_putnbr(pl.nor.z, 1);
    ft_putstr("  ");
    ft_putnbr(pl.col.x, 1);
    ft_putstr(",");
    ft_putnbr(pl.col.y, 1);
    ft_putstr(",");
    ft_putnbr(pl.col.z, 1);
    ft_putstr("\n");
}

void    ft_print_cylinder(t_cylinder cy)
{
    ft_putstr("cy ");
    ft_putnbr(cy.cor.x, 1);
    ft_putstr(",");
    ft_putnbr(cy.cor.y, 1);
    ft_putstr(",");
    ft_putnbr(cy.cor.z, 1);
    ft_putstr("  ");
     printf("%f\t%f\t%f\n", cy.nor.x, cy.nor.y, cy.nor.z);
/*
    ft_putnbr(cy.nor.x, 1);
    ft_putstr(",");
    ft_putnbr(cy.nor.y, 1);
    ft_putstr(",");
    ft_putnbr(cy.nor.z, 1);
    */
    ft_putstr("  ");
    ft_putnbr(cy.d, 1);
    ft_putstr("  ");
    ft_putnbr(cy.h, 1);
    ft_putstr("  ");
    ft_putnbr(cy.col.x, 1);
    ft_putstr(",");
    ft_putnbr(cy.col.y, 1);
    ft_putstr(",");
    ft_putnbr(cy.col.z, 1);
    ft_putstr("\n");
}

void    ft_print_triangle(t_triangle tr)
{
    ft_putstr("tr ");
    ft_putnbr(tr.x.x, 1);
    ft_putstr(",");
    ft_putnbr(tr.x.y, 1);
    ft_putstr(",");
    ft_putnbr(tr.x.z, 1);
    ft_putstr("  ");
    ft_putnbr(tr.y.x, 1);
    ft_putstr(",");
    ft_putnbr(tr.y.y, 1);
    ft_putstr(",");
    ft_putnbr(tr.y.z, 1);
    ft_putstr("  ");
    ft_putnbr(tr.z.x, 1);
    ft_putstr(",");
    ft_putnbr(tr.z.y, 1);
    ft_putstr(",");
    ft_putnbr(tr.z.z, 1);
    ft_putstr("  ");
    ft_putnbr(tr.col.x, 1);
    ft_putstr(",");
    ft_putnbr(tr.col.y, 1);
    ft_putstr(",");
    ft_putnbr(tr.col.z, 1);
    ft_putstr("\n");
}