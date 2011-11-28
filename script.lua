print( ShowMessage("Wellcome to China Airlines Search System") );

a = airplane.new(300, 14000, "boeing")
print(a:getseat())
print(a:getrange())
print(a:getname())

a:setseat(350)
print(a:getseat())
a:setrange(11000)
print(a:getrange())
a:setname("airbus")
print(a:getname())