#ifndef POINT_HPP
#define POINT_HPP
#include <immintrin.h>

#define mD __m256d

class Point {
	public: 
		Point(double x, double y, double vx, double vy, double mass, double fx, double fy, int r, int g, int b);
	
		bool updatePosition(double dt, double width, double height);
		int updateVelocity(double dt);
	
		double getX() const {return m_x;};
		double getY() const {return m_y;};

		double getVx() const {return m_vx;};
		double getVy() const {return m_y;};

		double getFx() const {return m_fx;};
		double getFy() const {return m_fy;};

		double getMass() const {return m_mass;};

		void setX(double x) {m_x = x;};
		void setY(double y) {m_y = y;};

		void setVx(double vx) {m_vx = vx;};
		void setVy(double vy) {m_vy = vy;};

		void setFx(double fx) {m_fx = fx;};
		void setFy(double fy) {m_fy = fy;};

		void setMass(double mass) {m_mass = mass;};
		//double getX() const {return _mm256_cvtsd_f64(data);};
		//double getY() const {return _mm256_cvtsd_f64(_mm256_permute4x64_pd(data,1));};

		//double getVx() const {return _mm256_cvtsd_f64(_mm256_permute4x64_pd(data,2));};
		//double getVy() const {return _mm256_cvtsd_f64(_mm256_permute4x64_pd(data,3));};

		//double getFx() const {return _mm256_cvtsd_f64(data2);};
		//double getFy() const {return _mm256_cvtsd_f64(_mm256_permute4x64_pd(data2,1));};

		//double getMass() const { return _mm256_cvtsd_f64(_mm256_permute4x64_pd(data2,2));};

		//void setX(double x) {data = _mm256_blend_pd(data, _mm256_set1_pd(x), 1);};
		//void setY(double y) {_mm256_blend_pd(data, _mm256_set1_pd(y), 2);};

		//void setVx(double vx) {_mm256_blend_pd(data, _mm256_set1_pd(vx), 4);};
		//void setVy(double vy) {_mm256_blend_pd(data, _mm256_set1_pd(vy), 8);};

		//void setFx(double fx) {_mm256_blend_pd(data, _mm256_set1_pd(fx), 1);};
		//void setFy(double fy) {_mm256_blend_pd(data, _mm256_set1_pd(fy), 2);};

		//void setMass(double mass) {_mm256_blend_pd(data, _mm256_set1_pd(mass), 4);};

		void setR(int r) {m_r = r;};
		void setG(int g) {m_g = g;};
		void setB(int b) {m_b = b;};
		
		int getR() const {return m_r ;};
		int getG() const {return m_g ;};
		int getB() const {return m_b ;};

	private:
		__m256d data;  // x, y, vx, vy,
		__m256d data2; // Fx, Fy, mass, 0
		double m_x, m_y;
		double m_vx, m_vy;
		double m_fx, m_fy;
		double m_mass;
		int m_r,m_g,m_b;
};
#endif
