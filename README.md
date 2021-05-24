
## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Requirements: 

Example:

``` bash
> mkdir build && cd build
> cmake .. # options: -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release], Debug is default
> make
> ./main
> make test      # Makes and runs the tests.
> make coverage  # Generate a coverage report.
> make doc       # Generate html documentation.
```
///////////////////////////////////////////////////////////

-brak dokumentacji
- ułożenie plików lub folderów może w minimalnym stopniu różnić się od orginalnego repozytorium z github zad.4, ponieważ pracowałem na repozytorium zad.3 przerabiając i edytując rotacje 2d
