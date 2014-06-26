$(document).ready(function(){
  $('.donation-amount').click(function(evt){
    evt.preventDefault();
    $('#donation-input').attr('value', $(this).text());
  });
});

$(document).foundation();
