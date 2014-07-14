$(document).ready(function(){
  $('.donation-amount').click(function(evt){
    evt.preventDefault();
    $('#donation-input').attr('value', $(this).text());
  });

  $('#no-end').click(function(){
    $('#campaign-dates').fadeToggle();  
  });

  $('#team-form, #indy-form').hide();
  $('#team, #indy').click(function(){
    var forms = '#' + $(this).attr('id') + '-form';
    formToShow = $(forms);
    if (forms == '#indy-form'){
      formToShow.fadeIn(); 
      $('#team-form').hide();
    } else {
      formToShow.fadeIn(); 
      $('#indy-form').hide();
    }
  });

  $('#team-member-form').hide();
  $('#custom-team-member').click(function(){
    $('#team-member-form').fadeToggle(); 
  });
 
  $('#indy-list').hide();
  $('a[href="#team-list"]').click(function(e){
    e.preventDefault();
    $('#indy-list').hide();
    $('#team-list').fadeIn();
    $(this).removeClass('muted');
    $('a[href="#indy-list"]').addClass('muted');
  });

  $('a[href="#indy-list"]').click(function(e){
    e.preventDefault();
    $('#team-list').hide();
    $('#indy-list').fadeIn();
    $(this).removeClass('muted');
    $('a[href="#team-list"]').addClass('muted');
  });

  $('.read-more-text').hide();
  $('.read-more').click(function(e){
    e.preventDefault();
    changeText($(this));
    $(this).parent().parent().find('.read-more-text').slideToggle();
  });

  var changeText = function(el){
    if (el.text() === 'Read more...') {
      el.text('Hide');
    }else if (el.text() === 'Hide') {
      el.text('Read more...');
    } 
  }
});

$(document).foundation();
