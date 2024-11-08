#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace mt
{

	class Circle
	{
		float m_r; // ���������� ��� �������
		float m_x, m_y; //���������� ��� ��������� 
		float m_v; // �������� �����
		float m_vx, m_vy; // ������� �������� �� X � Y 
		float m_alfa; // ���� ����������� 
		sf::CircleShape m_shape; // ������ ������ CircleShape ��� �����

	public:
		Circle() = default; // ����������� ��-���������

		Circle(float x, float y, float r, float v, float alfa) // ����������� �������������� ����������, �������� � ���� ����������� 
		{
			Setup(x, y, r, v, alfa); // ���������� ����� ��� ������������� ���������� 
		}

		void Setup(float x, float y, float r, float v, float alfa) //����� ��� ��������� ���������� ���������, �������� � ���� ����������� 
		{
			m_x = x; // ������������� ���������� X
			m_y = y; // ������������� ���������� Y
			m_r = r; // ������������� ������
			m_v = v; // ������������� ��������
			m_alfa = alfa; // ������������� ���� ����������� 
			m_vx = m_v * cos(m_alfa); // ��������� ������ �������� �� X
			m_vy = m_v * sin(m_alfa); // ��������� ������ �������� �� Y
			m_shape.setOrigin(m_r, m_r); // ������������� ������ ��������� � ����� �����
			m_shape.setRadius(m_r); // ������������� ������ �����
			m_shape.setPosition(m_x, m_y); // ������������� ���������� ����� �� ������
			int color_r = rand() % 256; // ��������� ������� ��������
			int color_g = rand() % 256; // ��������� ������� ������� 
			int color_b = rand() % 256; // ��������� ������� ������
			m_shape.setFillColor(sf::Color::Color(color_r, color_b, color_g, 255)); // ������������� ���� ������� �����
			m_shape.setOutlineThickness(-10.f); // ������������� ������� ������� �����
			m_shape.setOutlineColor(sf::Color(250, 150, 100)); // ������������ ���� �����
		}

		sf::CircleShape Get() // ������ ��� ��������� �����
		{
			return m_shape;
		}

		float X() { return m_x; } // ������ ��� ��������� X 
		float Y() { return m_y; } // ������ ��� ��������� Y
		float R() { return m_r; } // ������ ��� ��������� �������
		float Alfa() { return m_alfa; } // ������ ��� ��������� ���� �����������
		//void Alfa(float alfa)
		//{
		//	m_alfa = alfa;
		//}

		float V() { return m_v; } // ������ ��� ��������� ��������

		void Vx(float vx) { m_vx = vx; } // ����� ��� ��������� ������� ������� �� X
		void Vy(float vy) { m_vy = vy; } // ����� ��� ��������� ������� �������� �� Y
		float Vx() { return m_vx; } // ������ ��� ��������� ������� �������� �� X
		float Vy() { return m_vy; } // ������ ��� ��������� ������� �������� �� Y


		void Move(float dt) // ����� ��� ����������� �����
		{
			m_x += m_vx * dt; // ��������� ���������� X ������ � ����������� �� ������� 
			m_y += m_vy * dt; // ��������� ���������� Y ������ � ����������� �� ������� 
			m_shape.setPosition(m_x, m_y); // ������������� ����� ������� �����
		}
	};

}

