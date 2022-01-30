#pragma once
#include "Point2D.h"
#include "LineSegment.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <vector>

/*!
 * @brief Klasa do rysowania prymitywow
*/
class PrimitiveRenderer
{
public:
	/*!
	 * @brief Rysuje linie
	 * @param p0 Punkt 1
	 * @param p1 Punkt 2
	 * @param colour Kolor
	*/
	void line(Point2D p0, Point2D p1, ALLEGRO_COLOR colour);
	/*!
	 * @brief Rysuje prostokat
	 * @param p0 Punkt 1
	 * @param p1 Punkt 2
	 * @param colour Kolor
	 * @param filled Wypelniony
	*/
	void rectangle(Point2D p0, Point2D p1, ALLEGRO_COLOR colour, bool filled);
	/*!
	 * @brief Rysuje kolo
	 * @param p Punkt srodka
	 * @param radius Promien
	 * @param colour Kolor
	 * @param filled Wypelniony
	*/
	void circle(Point2D p,int radius, ALLEGRO_COLOR colour, bool filled);
	/*!
	 * @brief Rysuje trojkat
	 * @param p1 Punkt 1
	 * @param p2 Punkt 2
	 * @param p3 Punkt 3
	 * @param colour Kolor
	 * @param filled Wypelniony
	*/
	void triangle(Point2D p1, Point2D p2, Point2D p3, ALLEGRO_COLOR colour, bool filled);
	/*!
	 * @brief Rysuje punkt
	 * @param p Punkt
	 * @param colour Kolor
	*/
	void singlePoint(Point2D p, ALLEGRO_COLOR colour);
	/*!
	 * @brief Rysuje lancuch linii
	 * @param chain Vector z punkami 
	 * @param colour Kolor
	 * @param closed Czy zamkniety
	*/
	void polygonalChain(std::vector<Point2D> chain, ALLEGRO_COLOR colour, bool closed);
	/*!
	 * @brief Rysyje lancuch linii
	 * @param chain Vector z linesegmentami
	 * @param colour Kolor
	 * @param closed Czy zamkniety
	*/
	void polygonalChain(std::vector<LineSegment> chain, ALLEGRO_COLOR colour, bool closed);
	/*!
	 * @brief Rysuje okrag metoda z laboratorium
	 * @param p Punkt srodka
	 * @param r Promien
	 * @param colour Kolor
	*/
	void circle_lab(Point2D p, int r, ALLEGRO_COLOR colour);

};

