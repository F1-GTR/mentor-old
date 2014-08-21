var checkin = false;
function grayEmpty() {
    $('td span') .each(function (i, t)
    {
        var content = $(this) .text();
        if (content.length < 3)
        {
            $(this) .addClass('free');
        }
    });
};
function compReset()
{
    $('tr.hide') .each(function (i, t)
    {
        $(this) .removeClass('hide');
    });
    $('td span.eq') .each(function (i, t)
    {
        $(this) .removeClass('eq');
    });
    $('td span.neq') .each(function (i, t)
    {
        $(this) .removeClass('neq');
    });
    checkin = false;
    $('div.right').text("");
    $('div.left').text("");
};
function compHide(cell)
{
    var index = cell.index();
    $('tr') .each(function (i, t)
    {
        $(this) .children('td:eq(' + index + ')') .each(function (i, t)
        {
            var content = $(this) .text();
            if (content.length < 3)
            {
                $(this) .parent() .addClass('hide');
            }
        });
    });
};
function compEq(cell)
{
    var index = cell.parent() .index();
    var etalon = cell.text();
    if (etalon.length > 2 )
    {
        checkin = true;
        $('div.right') .text(etalon);
        compHide(cell.parent());
        $('tr') .each(function (i, t)
        {
            var checking = $('tr:eq(' + i + ') td:eq(' + index + ') span');
            var content = checking.text();
            if (content.length > 2)
            {
                //alert(i+"|"+etalon+":"+etalon.length+"|"+content+":"+content.length);
                if (content == etalon)
                {
					checking.removeClass('neq');
                    checking.addClass('eq');
                } 
                else
                {
					checking.removeClass('eq');
                    checking.addClass('neq');
                }
            }
        });
    }
};
$(document) .ready(function () {
    $('div.right').text("");
    $('div.left').text("");
    
    $('td span') .click(function ()
    {
        $('div.left') .text($(this) .text());
        compEq($(this));
    });
    $('a.drop') .click(function ()
    {
        compReset();
    });
    grayEmpty();
});
/*
Exception: [object Object]
*/
/*
Exception: [object Object]
*/
/*
Exception: missing ; before statement
@Scratchpad/1:75
*/

/*
Exception: missing ; before statement
@Scratchpad/1:74
*/