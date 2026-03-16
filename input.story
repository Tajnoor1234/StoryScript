story FullDemo begins

character x holds 10;
character y holds 5;

x holds x + y;

when x > 10
    narrate x;
otherwise
    narrate y;
end choice

during x < 30
    x holds x + 5;
    narrate x;
end cycle

end story