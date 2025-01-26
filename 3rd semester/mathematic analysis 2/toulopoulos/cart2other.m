function cart2other (x,y,z)

r = sqrt(x^2 + y^2);
ro = sqrt(x^2 + y^2 + z^2);

if x > 0 && y >= 0;
  thita = atan(y/x);
elseif x > 0 && y < 0
  thita = 2*pi + atan(y/x);
elseif x < 0
  thita = pi + atan(y/x);
elseif x = 0 && y > 0
  thita = pi/2;
elseif x = 0 && y < 0
  thita = (3*pi)/2;
endif

fi = acos(z/ro);

disp("Cartesian to cylindrical\n")

r
thita
z

disp("Cartesian to circular\n")

ro
thita
fi

endfunction
