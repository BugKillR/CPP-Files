#include "./Point.hpp"

int main( void ) {
	Point a(15, 0);
	Point b(-10, 0);
	Point c(5, 10);

	Point inside(5, 5);
	Point inside2(14, 0.99804684f);
	Point edge(5, 0);
	Point vertex(0, 0);

	std::cout << "inside : " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
	std::cout << "inside2: " << (bsp(a, b, c, inside2) ? "true" : "false") << std::endl;
	std::cout << "edge   : " << (bsp(a, b, c, edge) ? "true" : "false") << std::endl;
	std::cout << "vertex : " << (bsp(a, b, c, vertex) ? "true" : "false") << std::endl;

	return (0);
}
