story FullDemo begins

character a holds 5;
character b holds 10;
character i holds 0;

listen i;

when (a < b) and not (i == 0)
    narrate a;
otherwise
    narrate b;
end choice

during i < 3
    narrate i;
    i holds i + 1;
end cycle

chapter multiply takes x, y
    character result holds x * y;
    return result
end chapter

character c holds multiply(a, b);

narrate c;

end story