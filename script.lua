print( ShowMessage("Wellcome to China Airlines Search System") );

a = airplane.new(300, 14000)
print(airplane.getseat(a))
print(airplane.getrange(a))

airplane.setseat(a, 350)
print(airplane.getseat(a))
airplane.setrange(a, 11000)
print(airplane.getrange(a))