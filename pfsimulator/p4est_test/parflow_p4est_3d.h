#ifndef PARLOW_P4EST_3D_H
#define PARLOW_P4EST_3D_H

#include "parflow_p4est.h"
#include <p8est_lnodes.h>

typedef struct parflow_p4est_grid_3d {

    int             dim;
    p8est_t        *forest;
    p8est_connectivity_t *connect;
    p8est_ghost_t  *ghost;

} parflow_p4est_grid_3d_t;

typedef struct parflow_p4est_qiter_3d {

    p8est_t        *forest;
    p8est_connectivity_t *connect;
    p4est_topidx_t  tt;
    p8est_tree_t   *tree;
    sc_array_t     *tquadrants;
    int             owner_rank; /* processor owning current quadrant */
    int             Q;          /* quadrants in this tree */
    int             q;          /* index of current quad in this tree */
    p8est_quadrant_t *quad;     /* current quadrant */
    double          v[3];       /* lower left corner of current quadrant */

} parflow_p4est_qiter_3d_t;

typedef struct parflow_p4est_giter_3d {

    p8est_ghost_t  *ghost;
    sc_array_t     *ghost_layer;
    p8est_connectivity_t *connect;
    int             owner_rank; /* processor owning current quadrant */
    int             G;          /* ghosts quadrants in this layer */
    int             g;          /* index of current quad in this layer */
    p8est_quadrant_t *quad;     /* current quadrant */
    double          v[3];       /* lower left corner of current quadrant */

} parflow_p4est_giter_3d_t;

parflow_p4est_grid_3d_t *parflow_p4est_grid_3d_new(int Px, int Py, int Pz);

void            parflow_p4est_grid_3d_destroy(parflow_p4est_grid_3d_t *
                                              pfgrid);

void            parflow_p4est_qcoord_to_vertex_3d(p8est_connectivity_t *
                                                  connect,
                                                  p4est_topidx_t treeid,
                                                  p8est_quadrant_t *
                                                  quad, double v[3]);

parflow_p4est_qiter_3d_t
    * parflow_p4est_qiter_init_3d(parflow_p4est_grid_3d_t * pfg);

int             parflow_p4est_qiter_isvalid_3d(parflow_p4est_qiter_3d_t *
                                               qit_3d);

void            parflow_p4est_qiter_next_3d(parflow_p4est_qiter_3d_t *
                                            qit_3d);

void            parflow_p4est_qiter_destroy_3d(parflow_p4est_qiter_3d_t *
                                               qit_3d);

#endif                          // !PARLOW_P4EST_3D_H