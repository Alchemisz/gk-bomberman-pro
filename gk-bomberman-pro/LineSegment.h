#pragma once
#include "Point2D.h"

/*!
 * @brief Klasa rysujaca prymityw linesegment
*/
class LineSegment {
	private:
		//! Wspolrzedne poczatku
		Point2D beggining;
		//! Wspolrzedne konca
		Point2D end;
	public:
		/*!
		 * @brief Konstruktor z dwoma punktami
		 * @param points Punkty
		*/
		LineSegment(Point2D points[2]);
		/*!
		 * @brief Konstruktor z dwoma punktami
		 * @param beggining Poczatek
		 * @param end Koniec
		*/
		LineSegment(Point2D beggining, Point2D end);
		/*!
		 * @brief Ustawia poczatek linesegmentu
		 * @param point Punkt poczatkowy
		*/
		void setBeggining(Point2D point);
		/*!
		 * @brief Ustawia koniec linesegmentu
		 * @param point Punkt koncowy
		*/
		void setEnd(Point2D point);
		/*!
		 * @brief Zwraca punkt poczatkowy linesegmentu
		 * @return Punkt poczatkowy
		*/
		Point2D getBeggining();
		/*!
		 * @brief Zwraca punkt koncowy linesegmentu
		 * @return Punkt koncowy
		*/
		Point2D getEnd();
};