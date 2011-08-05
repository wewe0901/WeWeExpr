/*
**      File:   nrutil.h
**      Purpose: Memory allocation routines borrowed from the
**              book "Numerical Recipes" by Press, Flannery, Teukolsky,
**              and Vetterling.
**              state sequence and probablity of observing a sequence
**              given the model.
**      Organization: University of Maryland
**
**      $Id: nrutil.h,v 1.2 1998/02/19 16:32:42 kanungo Exp kanungo $
*/

float *vector(int nl,int nh);
float **matrix();
float **convert_matrix();
double *dvector();
double **dmatrix(int nrl,int nrh,int ncl,int nch);
int *ivector(int nl,int nh);
int **imatrix(int nrl,int nrh,int ncl,int nch);
float **submatrix();
void free_vector();
void free_dvector();
void free_ivector(int* v,int nl,int nh);
void free_matrix();
void free_dmatrix(double ** m,int nrl,int nrh,int ncl,int nch);
void free_imatrix(int** m,int nrl,int nrh,int ncl,int nch);
void free_submatrix();
void free_convert_matrix();
void nrerror();
