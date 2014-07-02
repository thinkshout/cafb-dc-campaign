$(document).ready(function(){
  $('.donation-amount').click(function(evt){
    evt.preventDefault();
    $('#donation-input').attr('value', $(this).text());
  });

  $('#no-end').click(function(){
    $('#campaign-dates').fadeToggle();  
  });
});

$(document).foundation();
