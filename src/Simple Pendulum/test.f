      program test
      implicit none
      integer, parameter :: n = 500
      real, parameter :: g = 9.81
      real, parameter :: l = 1.0
      real, dimension(n) :: w, t
      real, dimension(n) :: theta
      real, parameter :: dt = 0.02
      integer :: i
      theta(1) = 0.02
      w(1) = 0
      t(1) = 0
      do i = 1, n-1
      w(i+1) = w(i) - (g/l) * theta(i) * dt
      theta(i+1) = theta(i) + w(i+1) * dt
      t(i+1) = t(i) + dt
      end do  
      do i = 1, n
      print *, t(i) ,  theta(i)
      end do
      end
