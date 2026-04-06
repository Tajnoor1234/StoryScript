story MultiplyDemo begins

character a holds 5;
character b holds 10;

chapter multiply takes x, y
    character result holds x * y;
    return result
end chapter

character c holds multiply(a, b);
narrate c;


end story